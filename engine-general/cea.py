# Caelus Engine Parameterization Script
# Authors: Tanmay Neema, Daniel DeConti, Jessica Chen, Liam West
# Original code & methods sourced from Jason Chen
# Project Caelus, 04 February 2021



"""
INPUTS:
    CEAgui
        - O/F = 
OUTPUTS:
    
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

# Input non-CEAgui vars from text file
def input_variables():
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
    vars["P3"] = get_exit_pressure(vars["altitude"])
    ceagui_name = file_name + "_ceagui"
    return vars, ceagui_name


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


def ceagui_inp(vars, ceagui_name):
    cea_exe_dir = "./CEAexec/cea-exec/"
    pressure_ratio = round(vars["P0"] / vars["P3"], 3)
    frozen = "frozen nfz=1" if bool(vars["frozen"]) else "equilibrium"
    # Make the file
    with open(cea_exe_dir + ceagui_name + ".inp", "w+") as f:
        line_1 = f"problem  case={ceagui_name} o/f={vars['o/f']},\n"
        f.write(line_1)
        line_2 = f"      rocket  {frozen}\n"
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


def driver_cea(ceagui_name):
    cea_exe_dir = "./CEAexec/cea-exec/"
    t1 = threading.Thread(target=type_with_delay, args=(ceagui_name, 0.25), daemon=True)
    t1.start()
    subprocess.call([cea_exe_dir + "FCEA2m.exe"],  cwd = cea_exe_dir)
    t1.join()
    print(f"Operation complete. {ceagui_name}.out saved to {cea_exe_dir}")
   


def cea_outparse(ceagui_name):
    cea_exe_dir = "./CEAexec/cea-exec/"
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

def print_outputs(vars):
    for key in vars:
        print(f"{key} = {round(vars[key], 3)}")



def cea_main(vars, ceagui_name):
    py_dir = os.path.dirname(__file__)
    os.chdir(py_dir)
    ceagui_inp(vars, ceagui_name)
    driver_cea(ceagui_name)
    cea_outparse(ceagui_name)

if __name__ == "__main__":
    py_dir = os.path.dirname(__file__)
    os.chdir(py_dir)
    temp = input_variables()
    vars = temp[0]
    ceagui_name = temp[1]
    ceagui_inp(vars, ceagui_name)
    driver_cea(ceagui_name)
    cea_outparse(ceagui_name)
    print_outputs(vars)
