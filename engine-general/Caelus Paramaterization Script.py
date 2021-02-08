# Caelus Engine Parameterization Script
# Daniel DeConti, np.tanmay Neema, Liam West, Jessica Chen, Project Caelus - 4 February 2021
# With too much code copy/pasted from Jason Chen
'''
Inputs
    Driving Parameters
        - F = Thrust (N)
        - P0 = Chamber Pressure (Pa)
        - ALT = Optimal Altitude (m)
    New
        - B = Burn Time (s)
        - Cv = Coefficient of flow (Gal/minute-np.sqrt(psi))
        - U = Ullage (%)
        - Sg = Specific gravity
        - DP = Pressure drop across injector (%)
        - VT = np.tank volume (L)
        - T = Temperature (K)

    CEAgui
        - k = Ratio of Specific Heats
        - T0 = Combustion Temperature (K)
        - M = Molecular Mass of Gas (kg/mol)
        - O/F = Oxidizer to Fuel Ratio
        - L* = Characteristic Chamber Length (m)
OUTPUTS:
    Nozzlecalc
        - Isp = Specific impulse at altitude, sec
        - Tt = Throat temperature, K
        - v2 = Effective exhaust velocity, m/sec
        - mdot = Mass flow rate, kg/sec
        - mdot_oxidizer = Mass flow rate of the oxidizer, kg/sec
        - mdot_fuel = Mass flow rate of the fuel, kg/sec
        - PR = Pressure ratio, dimensionless
        - ER = Expansion ratio, dimensionless
        - Te = Exit temperature, K
        - Mnum = Exit Mach number, dimensionless
        - At = Area of the throat, m^2
        - Ae = Area of the exit, m^2
        - Rt = Radius of the throat, m
        - Re = Radius of the exit, m
        - Rc = Radius of the chamber, m
        - Lc = Length of the chamber, m
        - Ldn = Length of the diverging nozzle, m
        - Lcn = Length of the converging nozzle, m
    New
        - Initial fuel mass
        - Initial oxidizer mass
        - Volumetric fuel flow rate
        - Volumetric oxidizer flow rate
        - System pressure drop (?)
        - Initial ethanol np.tank pressure
        - Initial nitrous np.tank pressure
'''
import os
import sys
import csv
import math
import numpy as np
import time
import subprocess
import threading
import pyautogui

# Input non-CEAgui vars from text file
def input_variables():
    global file_path, input_vars
    print('Input variables using a .txt file. Enter floats only')
    print('Please list them in the order they are listed at the top of the file, i.e. \n Thrust:___ \n Chamber Pressure:___ \n . \n . \n .')
    file_path = input("Enter file path with .txt: ")

    input_vars = dict()
    try:
        with open(file_path) as f:
            for line in f:
                colon_index = line.find('=')
                name = float(line[:colon_index].strip())
                value = float(line[colon_index+1:].strip())
                input_vars[name] = value
    except IOError:
        print('Please ensure input.txt is named correctly and in the correct depository')
    except ValueError:
        print('Please ensure inputs are entered as floats with no other text in the file')
    ceagui_inp()

def get_exit_pressure(h: int or float):
    """
    Sourced from NASA Glenn Research Center's Earth Atmosphere Model.
    Computes and sets the ambient pressure, P3, based on inputted altitude (meters).
    P3 has units in pascals. Note: The intermediate temperature calculations use Celsius.
    :param h: Altitude, in meters.
    :return P3: Ambient pressure at altitude, in pascals.
    """
    if (h >= 25000):  # Upper Stratosphere
        T = -131.21 + 0.00299 * h
        P3 = (2.488 * ((T + 273.1) / 216.6) ** (-11.388))*1000
    elif (11000 < h < 25000):  # Lower Stratosphere
        T = -56.46
        P3 = (22.65 * math.exp(1.73 - 0.000157 * h))*1000
    else: # Troposphere
        T = 15.04 - 0.00649 * h
        P3 = (101.29 * ((T + 273.1) / 288.08) ** (5.256))*1000
    return P3

def ceagui_inp():
    global P3
    problem_type = "rocket"
    frozen = False
    equilibrium = False
    while frozen == equilibrium:
        reaction = input("Frozen flow combustion or equilibrium combustion: ")
        frozen = reaction.find("frozen") != -1
        equilibrium = reaction.find("equilibrium") != -1
    if frozen:
        nfz = 1
    h = float(input("Enter altitude (m):"))
    P0 = input_vars[2]
    P3 = get_exit_pressure(h)
    pressure_ratio = P0/P3
    OF = input_vars[-2]
    temp = input_vars[10]

    # Make the file
    global ceagui_inp,ceagui_inp_name
    ceagui_inp = file_path[:file_path.find(".")-1] + "_ceag ui"
    slash_insnp.tances = [index for index, val in enumerate(ceagui_inp) if val == "/" or "\\"]
    ceagui_inp_name = ceagui_inp[ceagui_inp[max(slash_insnp.tances):]]
    with open(ceagui_inp + ".inp", "w+") as f:
        line_1 = "problem  case={} o/f={}\n".format(ceagui_inp_name, input_vars[-2])
        f.write(line_1)
        line_2 = "      {}".format(problem_type)
        if equilibrium:
            line_2 += "  equilibrium"
        if frozen:
            line_2 += "  frozen  nfz={}".format(nfz)
        line_2 += "\n"
        f.write(line_2)
        line_3 = "  p,bar={}\n".format(P0)
        f.write(line_3)
        line_4 = "  np.pi/p={}.4f\n".format(pressure_ratio)
        f.write(line_4)
        line_7 = "react\n"
        f.write(line_7)
        line_8 = "  fuel=C2H5OH(L) wt=95  t,k={}\n".format(temp)
        f.write(line_8)
        line_9 = "  fuel=H2O(L) wt=5  t,k={}\n".format(temp)
        f.write(line_9)
        line_10 = "  oxid=N2O wt=100  t,k={}\n".format(temp)
        # For liquid oxygen: line_10 = "  oxid=O2(L) wt=100  t,k={}\n".format(lox_temp)
        f.write(line_10)
        line_11 = "end"
        f.write(line_11)
        f.close()
        print("Operation complete. {} saved to {}".format(ceagui_inp, os.getcwd()))
        driver_cea()

def type_with_delay(dir_name: str, delay: int or float):
    time.sleep(delay)
    pyautogui.typewrite(dir_name)
    pyautogui.press("enter")

def driver_cea():
    t1 = threading.Thread(target=type_with_delay, args=(ceagui_inp, 0.25), daemon=True)
    t1.start()
    subprocess.call(["FCEA2m.exe"])
    t1.join()
    print("Operation complete. {}.out saved to {}.out".format(ceagui_inp_name, ceagui_inp))
    cea_outparse()

def cea_outparse():
    global cea_filename
    csv_filename = f"{ceagui_inp}.csv"
    cea_filename = f"{ceagui_inp}.out"
    delimiter = "THEORETICAL ROCKET PERFORMANCE ASSUMING EQUILIBRIUM"
    with open(csv_filename, mode='w', newline="") as csv_f:
        with open(cea_filename, mode='r') as cea_f:
            cea_lines = cea_f.readlines()
            file_writer = csv.writer(csv_f, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
            unique_rows = set()
            row = ["O/F", "P0 (BAR)", "P1 (BAR)", "T0 (K)", "M (1/n)", "GAMMA", "CSTAR (M/SEC)", "ISP (M/SEC)"]
            dims = len(row)
            for i, line in enumerate(cea_lines):
                if delimiter in line:  # Clear the row and append to a new one
                    assert len(row) == dims
                    if str(row) not in unique_rows:
                        unique_rows.add(str(row))
                        file_writer.writerow(row)
                        print(row)
                    row = []
                    continue
                line = line.strip()
                if "O/F=" in line:
                    temp = line.split()
                    row.append(temp[1])
                if "P, BAR" in line:
                    temp = line.split()
                    row.append(temp[2])
                    row.append(temp[3])
                if "T, K" in line:
                    temp = line.split()
                    row.append(temp[2])
                if "M, (1/n)" in line:
                    temp = line.split()
                    row.append(temp[2])
                if "GAMMAs" in line:
                    temp = line.split()
                    row.append(temp[1])
                if "CSTAR, M/SEC" in line:
                    temp = line.split()
                    row.append(temp[2])
                if "Isp, M/SEC" in line:
                    temp = line.split()
                    row.append(temp[2])
    print("Operation complete. CSV file saved to {}".format(csv_filename))
    calculate()

def calculate():
    """
    Attempts to calculate and print values.
    """
    global cea_outputs
    cea_outputs= []
    with open(cea_filename) as f:
        for line in f:
            colon_index = line.find(':')
            value = float(line[colon_index + 1:])
            cea_outputs.append(value)
    F = cea_outputs[0]
    P0 = cea_outputs[1]
    ALT = cea_outputs[2]
    OF = cea_outputs[3]
    T0 = cea_outputs[4]
    M = cea_outputs[5]
    k = cea_outputs[6]
    Lstar = cea_outputs[7]

    try:  # Attempt to calculate values
        R = (8314.3 / M)
        PR = (P3 / P0)
        AR = (((k + 1) / 2) ** (1 / (k - 1))) * ((P3 / P0) ** (1 / k)) * (
            np.sqrt(((k + 1) / (k - 1)) * (1 - ((P3 / P0) ** ((k - 1) / k)))))
        ER = 1 / AR
        Tt = (2 * T0) / (k + 1)
        v2 = np.sqrt((2 * k / (k - 1)) * ((R) * T0) * (1 - ((P3 / P0) ** ((k - 1) / k))))
        mdot = F / v2
        mdot_fuel = (mdot / (OF + 1))
        mdot_oxidizer = (mdot / (OF + 1)) * OF
        Isp = F / (mdot * 9.80655)
        Te = T0 / ((P0 / P3) ** ((k - 1) / k))
        Mnum = (v2 / (np.sqrt(k * (R) * (Te))))
        At = ((mdot) * (np.sqrt((k * R * T0)))) / (k * P0 * (np.sqrt(((2 / (k + 1)) ** ((k + 1) / (k - 1))))))
        Ae = ER * At
        Rt = np.sqrt(At / np.pi)
        Re = np.sqrt(Ae / np.pi)
        Ac = Ae
        Rc = np.sqrt((Ac) / np.pi)
        Lc = ((At) * Lstar) / (Ac)
        Ldn = ((Re) - (Rt)) / (np.tan(np.deg2rad(15)))
        Lcn = ((Rc) - (Rt)) / (np.tan(np.deg2rad(45)))


    except (ValueError, ZeroDivisionError):  # Exception thrown
        print("\n", "Error while attempting to solve. Please enter a valid value"
              " for every parameter.")

if __name__ == "__main__":
    input_variables()