import json
import os
import numpy as np
import pandas as pd 
import matplotlib.pyplot as plt

file = open(os.path.join("C:\\", "Users", "Ron", "ProjectCaelus", "propulsion", "cold-flow-data", "black_box_COLDFLOW_pi.txt"), "r")
original_timestamp, num_transducers, num_thermocouples = 0, 4, 0

transducers = [f'PT-{i}' for i in range(1, num_transducers + 1)]
thermocouples = [f'TC-{i}' for i in range(1, num_thermocouples + 1)]
sensors = transducers + thermocouples

data = []
for line in file:
    raw_data = json.loads(line)
    if raw_data['header'] == 'heartbeat' and raw_data['message'] == {'response': 'OK'}:
        timestamp = raw_data['timestamp']
        if original_timestamp == 0:
            original_timestamp = timestamp
        timestamp -= original_timestamp
        count_since_timestamp = 0
    if raw_data['header'] == 'sensor_data':
        batch = [timestamp + count_since_timestamp * (3/5)]
        for i, sensor in enumerate(sensors):
            batch.append(raw_data['message']['pressure'][sensor]['value'][1])
        data.append(batch)
        count_since_timestamp += 1

df = pd.DataFrame(data, columns=['timestamp'] + sensors)
print(list(df["PT-4"]))
print("MAX:", max(list(df["PT-4"])))
plt.plot(list(df["PT-4"][1750:]))
plt.show()

max_pressure = max([max(df[sensor]) for sensor in sensors])
fig = plt.figure()
fig.set_size_inches(8, 8)
ax = fig.subplots(2, 2)
for i, sensor in enumerate(sensors):
    axis = ax[i//2, i%2]
    axis.plot(df['timestamp'], df[sensor])
    axis.set_xlabel("Time (Seconds)")
    axis.set_ylabel("Pressure (PSI)")
    axis.set_title(f"Pressure Over Time - {sensor}")
    axis.set_ylim(0, max_pressure)

fig.tight_layout()
plt.show()

for i, sensor in enumerate(sensors):
    plt.plot(df['timestamp'], df[sensor], label=sensor)
plt.xlabel("Time (Seconds)")
plt.ylabel("Pressure (PSI)")
plt.title(f"Pressure Over Time - All Sensors")
plt.ylim(0, max_pressure)
plt.legend()
plt.show()

plt.clf()
start, end = 1787, 1792
time_segment, pressure_segment = df['timestamp'][start:end], df['PT-3'][start:end]
time_change, pressure_change = max(time_segment) - min(time_segment), max(pressure_segment) - min(pressure_segment)
volume = 3.0 # L
volume_change = (max(pressure_segment) * volume) / min(pressure_segment) - volume# L
volumetric_flow_rate = volume_change / time_change # L/s
print(f"Volume Change {volume_change} L\nPressure Change: {pressure_change} PSI\nTime: {time_change} sec\nVolumetric Flow Rate: {volumetric_flow_rate} L/s\nMass Flow Rate: {volumetric_flow_rate} kg/s")
plt.plot(time_segment, pressure_segment)
plt.show()