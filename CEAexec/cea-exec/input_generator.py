# Generates an .inp file (for CEA2) given parameters in the __main__ method
# Jason Chen, Project Caelus, 12/14/2019

import sys
import math
import os
import numpy as np


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


if __name__ == "__main__":
    of_ratios = np.arange(1.2, 1.61, 0.05)
    chamber_pressures = np.arange(1, 3.1, 0.2)  # MPa
    problem_type = "rocket"
    altitude = 5000  # Meters
    equilibrium = True  # Tends to underestimate engine performance
    frozen = False  # Tends to overestimate engine performance
    if frozen:
        nfz = 1  # Freezing point is at the throat
    chamber_pressures = [float("{:.1f}".format(float(x))) for x in chamber_pressures]
    of_ratios = ["{:.2f}".format(float(x)) for x in of_ratios]
    pressure_ratios = ["{:.5f}".format(x*1e6/get_exit_pressure(altitude)) for x in chamber_pressures]
    contraction_ratios = []
    exit_ratio = []
    temperature = 298  # Kelvin
    lox_temp = 90.17
    # Change the directory
    try:
        os.chdir(os.getcwd() + "/ethanol-75-lox")
    except FileNotFoundError or OSError:
        print("Input file directory not found.")
        sys.exit(0)
    # Make the file
    case_name = "ethanol-75-lox"
    filename = case_name + ".inp"
    with open(filename, "w+") as f:
        line_1 = "problem  case={} o/f={}\n".format(case_name, "".join([str(i) + "," for i in of_ratios]))
        f.write(line_1)
        line_2 = "      {}".format(problem_type)
        if equilibrium:
            line_2 += "  equilibrium"
        if frozen:
            line_2 += "  frozen  nfz={}".format(nfz)
        line_2 += "\n"
        f.write(line_2)
        line_3 = "  p,bar={}\n".format("".join([str(x*10) + "," for x in chamber_pressures]))
        f.write(line_3)
        line_4 = "  pi/p={}\n".format("".join([str(x) + "," for x in pressure_ratios]))
        f.write(line_4)
        line_7 = "react\n"
        f.write(line_7)
        line_8 = "  fuel=C2H5OH(L) wt=75  t,k={}\n".format(temperature)
        f.write(line_8)
        line_9 = "  fuel=H2O(L) wt=25  t,k={}\n".format(temperature)
        f.write(line_9)
        line_10 = "  oxid=O2(L) wt=100  t,k={}\n".format(lox_temp)
        f.write(line_10)
        line_11 = "end"
        f.write(line_11)
        f.close()
        print("Operation complete. {} saved to {}".format(filename, os.getcwd()))