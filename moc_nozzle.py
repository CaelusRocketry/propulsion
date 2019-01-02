# Method of Characteristics for Minimum Length Supersonic Nozzle
# Created by Jason Chen, Project Caelus
# Thomas Jefferson High School for Science and Technology
# Developed on December 31st, 2018

"""

This program generates a minimum-length supersonic diverging nozzle contour using the
Method of Characteristics.

-------------------------------------------------------------------------------------
ALL CALCULATIONS ARE DONE IN STANDARD IMPERIAL (SI) UNITS, WITH TEMPERATURE IN KELVIN.
ANGLES IN RADIANS.
-------------------------------------------------------------------------------------


CALCULATION ASSUMPTIONS:
    1) Flow maintains equilibrium at the local pressure and enthalpy level (reversible).
    2) No heat transfer across gas-enclosure walls; closed system (adiabatic).
    3) By definition, the flow is isentropic due to assumptions 1 and 2.
    4) Flow composition is considered frozen (tends to underestimate performance by 1-4%).
    5) Working fluid obeys the perfect gas law.
    6) All species of the working fluid in the flow is gaseous.
    7) Wall friction is negligible and all boundary layer effects are ignored.
    8) The very purpose of this code is to ensure that there are no shock waves or other
        discontinuities within the nozzle flow. This program calculates a minimum length
        nozzle, meaning the diverging nozzle consists solely of the straightening section.
        The flow turns a sharp, convex corner at the throat, and it is from this point in
        which characteristic lines are computed.
    9) By definition, characteristics are curves within the flow in which velocity is
        continuous but the first derivative of velocity is discontinuous.
    10) The axis of symmetry of the nozzle is synonymous to the centerline upon which
        characteristic lines are reflected.
    11) Expansion of the working fluid is uniform and steady; no significant turbulence.
    12) Gas velocity, pressure, temperature, & density are all uniform across any section
        perpendicular to the nozzle axis.

INPUTS:
    - F = Desired thrust, N
    - P0 = Chamber pressure, Pa
    - P3 = Ambient pressure, Pa
    - T0 = Combustion chamber temperature, K
    - M = Molecular mass of the gas, kg/mol
    - M = Desired exit Mach number, dimensionless
    - Rt = Throat radius, mm
    - k = Ratio of specific heat capacities, cp/cv, dimensionless

OUTPUTS:
    - Set of (x,y) points representing the diverging nozzle contour.
    - Points are written to a text document (moc_output.txt).
    - NOTE: Export to Excel by selecting "space delimited" when importing data in Excel.
    - Plots of the characteristic lines generated (FEATURE NOT AVAILABLE AT THIS TIME).

"""
from math import atan, exp, sqrt
import numpy as np

def prompt():
    print("\n ----------------------------------------------------------------------",
          "\n", "Take parameters through keyboard inputs or from Excel file (moc_data.xlsx)?",
          "\n ----------------------------------------------------------------------")
    prompt = input("Enter INPUT or EXCEL: ")
    if(prompt == "INPUT"):

    elif(prompt == "EXCEL"):

    else:
        print("\n", "Invalid! Please enter INPUT or EXCEL to select your desired"
                    " input method.")
def take_input(s):
    """
    Prompt input from user.
    :param s: The message to display to the user.
    :return: The user's input as a `float`.
    """
    try:
        return float(input(s))
    except ValueError:
        print("\n", "Please make sure every input is a numeric value.")
        exit(0)

def print_header(string, key=lambda: 30):
    """
    Provides an easy way to print out a header.
    :param string: The header as a string.
    :param key: Length of the message.
    """
    print("\n")
    print((len(string) % 2) * '-' + '{:-^{width}}'.format(string, width=key()))

def calc_readings():
    """
    Defines user parameters from user input and calls a calculation.
    """
    global F, P0, ALT, T0, M, k
    F = take_input("Desired thrust (N): ")
    P0 = take_input("Chamber pressure (Pa): ")
    ALT = take_input("Altitude (m): ")
    T0 = take_input("Combustion chamber temperature (K): ")
    M = take_input("Gas molecular mass (kg/mol): ")
    k = take_input("Ratio of specific heats (cp/cv): ")
    calculate()

def exit_pressure(h):
    """
    Sourced from NASA Glenn Research Center's Earth Atmosphere Model.
    Computes and sets the ambient pressure, P3, based on inputted altitude (meters).
    P3 has units in pascals. Note: The intermediate temperature calculations use Celsius.
    :param h: Altitude, in meters.
    """
    global P3
    if (h >= 25000):  # Upper Stratosphere
        T = -131.21 + 0.00299 * h
        P3 = (2.488 * ((T + 273.1) / 216.6) ** (-11.388))/1000
    elif (11000 < h < 25000):  # Lower Stratosphere
        T = -56.46
        P3 = (22.65 * exp(1.73 - 0.000157 * h))/1000
    else: # Troposphere
        T = 15.04 - 0.00649 * h
        P3 = (101.29 * ((T + 273.1) / 288.08) ** (5.256))/1000

def PMfunct(gamma, mach):
    """
    Computes the Prandtl-Meyer angle based on the inputted local Mach number and ratio of
    specific heat capacities. The Prandtl-Meyer angle is the maximum angle at which a sonic
    flow (Mnum = 1) can turn a convex corner isentropically (without producing a shock).
    :param gamma: Ratio of specific heat capacities, dimensionless
    :param mach: Local Mach number, dimensionless
    :return: The Prandtl-Meyer angle, radians
    """
    sect1 = (gamma+1)/(gamma-1)
    sect2 = (mach**2)-1
    PMangle = sqrt(sect1)*atan(sqrt(sect1*sect2)) - atan(sqrt(sect2))
    return PMangle

def calculate():
    exit_pressure(ALT)
    PR = P3/P0 # Pressure ratio
    TR = PR**((k-1)/k) # Temperature ratio
    R = (8314.3/M) # Gas constant
    CTt = (2*k*R*T0)/(k-1) # Critical throat temperature (disputed equation?)
    CTp = ((2/(k+1))**(k/(k-1)))*P0 # Critical throat pressure
    CTv = sqrt((2*k*R*T0)/(k+1)) # Critical throat velocity
    v2 = sqrt((CTt)*(1-TR)) # Exit velocity
    mdot = F/v2 # Mass flow rate
    T2 = T0*TR # Exit temperature
    a2 = sqrt(k*R*T2) # Exit speed of sound
    Mnum2 = v2/a2 # Exit Mach number


if __name__ == "__main__":
    prompt()
