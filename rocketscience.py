#Uses thrust profiles to generate apogee and max velocity calculation
#Requires thrust profile (or you can use a solid motor profile that's in the json
#Doesn't currently take into consideration stability or other aerodynamic factors
import math
import json

dt = 0.001

#Constants: rho = air density, 
rho = 1.2
g = 9.81
json_file = open('C:/Users/Srikar/Documents/ProjectCaelus/propulsion/MOTOR_DATA.json')
MOTOR_MODELS = json.load(json_file)
motor = MOTOR_MODELS['Estes_C6'] ##CHANGE THIS TO CHOOSE MOTOR, also need to change I and T down below
mpoints = motor['points']

#Rocket Features
#M1 - mass of rocket + motor - propellant, M2 - mass of propellant, M - total mass
#A - Area of nose cone, Ap - Area of parachute
#Cd - Drag of rocket, Cdp - Drag of parachute
#I - Total impulse, T - Average Thrust, t - burn time, delay - parachute delay time
M1 = 0.04 + motor['tweight'] - motor['pweight']
M2 = motor['pweight']
M = M1+M2
A = pow(.0125,2)*math.pi
Ap = pow(.125,2)*math.pi
Cd = 0.75
Cdp = 1.75
I = 8.82 #Need to change based on motor
T = 4.74 #Need to change based on motor
t = mpoints[len(mpoints)-1][0]
delay = motor['delay'][2]

#RocketMime's terms
k = 0.5 * rho * Cd * A
Mg = M*g
q = math.sqrt((T - Mg) / k)
x = 2 * k * q / M
#print(k,Mg,q,x)
#print(q * math.exp(-1*x*t))

#Calculations: v = max velocity, ya = apogee, yb = boost distance, yc = coast distance
v = q * (1-math.exp(-1*x*t)) / (1+math.exp(-1*x*t))
#print((k*pow(v,2)))
yb = (-1*M/(2*k))*math.log((T-Mg-k*pow(v,2))/(T-Mg))
yc = (M/(2*k))*math.log((Mg+k*pow(v,2))/(Mg))

print("Using equations that people made:")
print("Max velocity: ",v)
print("Boost distance: ",yb)
print("Coast distance: ",yc)
print("Apogee: ", yb+yc)

print('----------')

altitude = 0
velocity = 0
acceleration = 0
steps = int(t/dt)
time = 0

#Arrays to store simulation
times = []
altitudes = []
velocities = []

#Motor points
cindex = 0
cslope = (mpoints[cindex+1][1]-mpoints[cindex][1])/(mpoints[cindex+1][0]-mpoints[cindex][0])
totalT = 0
for i in range(steps):
    time += dt
    if time > mpoints[cindex+1][0]:
        cindex += 1
        cslope = (mpoints[cindex+1][1]-mpoints[cindex][1])/(mpoints[cindex+1][0]-mpoints[cindex][0])
    T = cslope*(time - mpoints[cindex][0]) + mpoints[cindex][1]
    totalT += T*dt
#    print(T)
    D = (1/2) * rho * Cd * A * velocity * velocity
    acceleration = (T - D - (M*g))/M
    velocity += acceleration * dt
    M -= (M2/steps)
    altitude += velocity * dt

    times.append(time)
    altitudes.append(altitude)
    velocities.append(velocity)

while time < t + delay:
    time += dt
    D = (1/2) * rho * Cd * A * velocity * velocity
    acceleration = (- D - (M*g))/M
    velocity += acceleration * dt
    altitude += velocity * dt

    times.append(time)
    altitudes.append(altitude)
    velocities.append(velocity)

termV = math.sqrt((2*M)/(rho*Ap*Cdp))
while altitude > 0:
    time += dt
    D = (1/2) * rho * Cdp * Ap * velocity * velocity
    if velocity > 0:
        D *= -1
    acceleration = (D - (M*g))/M
    velocity += acceleration * dt
    altitude += velocity * dt

    times.append(time)
    altitudes.append(altitude)
    velocities.append(velocity)

apogee = max(altitudes)
maxVel = max(velocities)
print("Using Riemann sums and thrust modeling")
print("Apogee",apogee)
print("Max velocity",maxVel)
index = altitudes.index(apogee)
print("Time to apogee",times[index])
