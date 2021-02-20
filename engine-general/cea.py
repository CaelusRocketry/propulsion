# Caelus Engine Parameterization Script
# Authors: Tanmay Neema, Daniel DeConti, Jessica Chen, Liam West
# Original code & methods sourced from Jason Chen
# Project Caelus, 04 February 2021

# TODO: @Tanmay: Remove all uses of "global" and instead just pass around variables using return
# TODO: @Tanmay: Use a config.json file to take all inputs. Should have a single input() call only at the beginning asking
# whether the user wants to input via input() or via the config.json. Google for JSON tutorials; it's basically a dictionary.
# TODO: @Tanmay: Make the for loop in calcluate() that gets CEA vars write to a dictionary, not an array (so it's cleaner)
# TODO: @Tanmay: Write the outputs to a .txt/.csv file, and also print. Should output both inputs and outputs.

"""
INPUTS:
    Driving Parameters
        - F = Thrust (N)
        - P0 = Chamber pressure (Pa)
        - ALT = Optimal altitude (m)
    New
        - B = Burn time (s)
        - Cv = Coefficient of flow (gal/min - sqrt(psi))
        - U = Ullage (% of tank volume)
        - Sg = Specific gravity (dimensionless)
        - DP = Pressure drop across injector (%)
        - VT = Tank volume (L)
        - T = Temperature (K)
    CEAgui
        - k = Ratio of specific heats (dimensionless)
        - T0 = Combustion Temperature (K)
        - M = Molecular Mass of Gas (kg/mol)
        - O/F = Oxidizer to Fuel Ratio
        - L* = Characteristic Chamber Length (m)

OUTPUTS:
    Nozzle & General Engine Parameters
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
"""

import os
import sys
import csv
import math
import numpy as np
import time
import subprocess
import threading
import pyautogui

# Preprocessing
py_dir = os.path.dirname(__file__)
os.chdir(py_dir)
cea_exe_dir = "./CEAexec/cea-exec/"

# Input non-CEAgui vars from text file
def input_variables():
    global file_name, vars
    print("Input variables using a .txt file. Enter floats only. Ensure file is within folder of .py file.")
    print("Please list them in the order they are listed at the top of the file, i.e. \n Thrust=___ \n Chamber Pressure=___ \n . \n . \n .")
    
    file_ext = input("Enter file path with .txt: ")
    file_name = file_ext.split(".")[0]
    vars = dict()
    try:
        with open(file_ext) as f:
            for line in f:
                equal_index = line.find("=")
                name = line[:equal_index].strip()
                value = float(line[equal_index+1:].strip())
                vars[name] = value
    except IOError:
        print("Please ensure input.txt is named correctly and in the correct directory.")
    except ValueError:
        print("Please ensure inputs are entered as floats with no other text in the file")
    vars["frozen"] = "frozen nfz=1" if bool(vars["frozen"]) else "equilibrium"


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
    vars["P3"] = get_exit_pressure(vars["altitude"])
    pressure_ratio = round(vars["P0"] / vars["P3"], 3)

    # Make the file
    ceagui_name = file_name + "_ceagui"
    with open(cea_exe_dir + ceagui_name + ".inp", "w+") as f:
        line_1 = f"problem  case={ceagui_name} o/f={vars['o/f']},\n"
        f.write(line_1)
        line_2 = f"      rocket  {vars['frozen']}\n"
        f.write(line_2)
        line_3 = f"  p,bar={vars['P0']/100000},\n"
        f.write(line_3)
        line_4 = f"  pi/p={pressure_ratio},\n"
        f.write(line_4)
        line_5 = "react\n"
        f.write(line_5)
        line_6 = f"  fuel=C2H5OH(L) wt=95  t,k={vars['temp']}\n"
        f.write(line_6)
        line_7 = f"  fuel=H2O(L) wt=5  t,k={vars['temp']}\n"
        f.write(line_7)
        line_8 = f"  oxid=N2O wt=100  t,k={vars['temp']}\n"
        f.write(line_8)
        line_9 = "end"
        f.write(line_9)
        f.close()
        print(f"Operation complete. {ceagui_name}.inp saved to {cea_exe_dir}")
        


def type_with_delay(dir_name: str, delay: int or float):
    print(f"EXECUTING {dir_name}")
    time.sleep(delay)
    pyautogui.typewrite(dir_name)
    pyautogui.press("enter")


def driver_cea():
    ceagui_name = file_name + "_ceagui"
    t1 = threading.Thread(target=type_with_delay, args=(ceagui_name, 0.25), daemon=True)
    t1.start()
    subprocess.call([cea_exe_dir + "FCEA2m.exe"],  cwd = cea_exe_dir)
    t1.join()
    print(f"Operation complete. {ceagui_name}.out saved to {cea_exe_dir}")
   


def cea_outparse():
    ceagui_name = file_name + "_ceagui"
    csv_filename = f"{ceagui_name}.csv"
    cea_filename = f"{ceagui_name}.out"
    delimiter = "THEORETICAL ROCKET PERFORMANCE"
    with open(cea_exe_dir + csv_filename, mode="w", newline="") as csv_f:
        with open(cea_exe_dir + cea_filename, mode="r") as cea_f:
            cea_lines = cea_f.readlines()
            file_writer = csv.writer(csv_f, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
            row = ["O/F", "P0 (BAR)", "P1 (BAR)", "T0 (K)", "M (1/n)", "GAMMA", "CSTAR (M/SEC)", "ISP (M/SEC)"]
            file_writer.writerow(row)
            vals = []
            for line in cea_lines:
                if delimiter in line:
                    vals = []
                if "O/F=" in line:
                    temp = line.split()
                    vals.append(temp[1])
                if "P, BAR" in line:
                    temp = line.split()
                    vals.append(temp[2])
                    vals.append(temp[3])
                if "T, K" in line:
                    temp = line.split()
                    vals.append(temp[2])
                if "M, (1/n)" in line:
                    temp = line.split()
                    vals.append(temp[2])
                if "GAMMAs" in line:
                    temp = line.split()
                    vals.append(temp[1])
                if "CSTAR, M/SEC" in line:
                    temp = line.split()
                    vals.append(temp[2])
                if "Isp, M/SEC" in line:
                    temp = line.split()
                    vals.append(temp[2])
        file_writer.writerow(vals)
        i = 3
        while i < 8:
            vars[row[i].split()[0]] = float(vals[i]) 
            i += 1
    print("Operation complete. CSV file saved to {}".format(csv_filename))
    print(vars)

def print_outputs():
    pass


def print_header(string, key=lambda: 30):
    """
    Provides an easy way to print out a header.
    :param string: The header as a string.
    :param key: Length of the message.
    """
    print("\n")
    print((len(string) % 2)*'-' + '{:-^{width}}'.format(string, width=key()))


def cea_main(v):
    global vars = v
    ceagui_inp()
    driver_cea()
    return vars

if __name__ == "__main__":
    input_variables()
    ceagui_inp()
    driver_cea()
    cea_outparse()
    print_outputs()
