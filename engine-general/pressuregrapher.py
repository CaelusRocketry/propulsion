# Caelus Pressure Graphing
# Author: Tanmay Neema
# Project Caelus, 04 February 2021

#TODO: find right initial conditions

import matplotlib.pyplot as plt
import os
import csv
import argparse
import numpy as np



def data_parse(base_time: float, *file_names):
    ptp_read = []
    ptp_time = []
    pt5_read = []
    pt5_time = []
    pt7_read = []
    pt7_time = []
    pt8_read = []
    pt8_time = []
    for file_name in file_names:
        with open(file_name, newline='') as f:
            for line in f:
                packet = line.split()
                time = float(packet[0])
                read = float(packet[3])

                if packet[2].find("PTP") != -1:
                    ptp_read.append(read)
                    ptp_time.append(time - base_time)

                elif packet[2].find("PT5") != -1:
                    pt5_read.append(read)
                    pt5_time.append(time - base_time)

                elif packet[2].find("PT7") != -1:
                    pt7_read.append(read)
                    pt7_time.append(time - base_time)

                else:
                    pt8_read.append(read)
                    pt8_time.append(time - base_time)
    

    pressure_data = [ptp_read, ptp_time, pt5_read, pt5_time, pt7_read, pt7_time, pt8_read, pt8_time]

    return pressure_data


data_parse(1614453736.213266,"nitrous_water_test_1.txt")
        
def mass_calc(pressure_data):
    pt5_read = pressure_data[0]
    pt5_time = pressure_data[1]
    init_water = 3.7
    init_pressure = 770
    init_nitrogen = 23
    density_water = 4
    
    wat_mass = []
    mdot =[0]

    for pres_nitrogen in pt5_read:
        vol_water = init_nitrogen + init_nitrogen - init_nitrogen*init_pressure/pres_nitrogen
        mass_water = density_water*vol_water
        wat_mass.append(mass_water)
    
    for i in range(len(wat_mass)-1):
        avg_mdot = (wat_mass[i] - wat_mass[i+1])/(pt5_time[i+1]-pt5_time[i])
        mdot.append(avg_mdot)
    
    return wat_mass, mdot
    

def plot(pressure_data, mass_data):
    ptp_read = pressure_data[0]
    ptp_time = pressure_data[1]
    pt5_read = pressure_data[2]
    pt5_time = pressure_data[3]
    pt7_read = pressure_data[4]
    pt7_time = pressure_data[5]
    pt8_read = pressure_data[6]
    pt8_time = pressure_data[7]

    mdot = mass_data[1]
    wat_mass = mass_data[0]



    plt.figure(1)
    fig, axs = plt.subplots(4)
    fig.suptitle("Pressure Readings")
    axs[0].plot(ptp_time, ptp_read)
    axs[0].set_title('PTP')
    axs[1].plot(pt5_time, pt5_read, 'tab:orange')
    axs[1].set_title('PT5')
    axs[2].plot(pt7_time, pt7_read, 'tab:green')
    axs[2].set_title('PT7')
    axs[3].plot(pt8_time, pt5_read, 'tab:red')
    axs[3].set_title('PT8')

    
    plt.figure(2)
    fig, axs = plt.subplots(2)
    fig.suptitle("Mass Readings")
    axs[0].plot(pt5_time, wat_mass)
    axs[0].set_title('Mass')
    axs[1].plot(pt5_time, mdot, 'tab:orange')
    axs[1].set_title('dm/dt')
    plt.show()

pressure_data = data_parse(1614453736.213266,"nitrous_water_test_1.txt")
mass_data = mass_calc(pressure_data)
plot(pressure_data, mass_data)

        