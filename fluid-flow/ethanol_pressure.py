# Ethanol Tank Pressure Calculations
# Created by Tanmay Neema, Project Caelus
# Thomas Jefferson High School for Science and Tech
# Developed on January 31st, 2021
"""
This program is to calculate the ethanol tank pressure to ensure no backflow. NOTE: MAKING MODULE FOR CAELUS PROP MIGHT
BE POG IDEA


CALCULATION ASSUMPTIONS:
    1) Adiabatic Expansion of Gas
    2) Ideal Gas
    3) Incompressible Liquid
    4) Constant Mass Flow Rate

INPUTS:
    - Oxidizer to fuel ratio, unitless
    - Mass Flow Rate, kg/s
    - Chamber Volume, L
    - Initial Tank Pressure, Pa
    - Initial Ethanol Volume, L

OUTPUTS:
    - Final Tank Pressure
    - Difference in Pressure
"""


def take_inputs(s):
    try:
        return float(input(s))
    except ValueError:
        print("\n", "Please make sure every input is a numeric value.")
        exit(0)

def print_header(string, key=lambda: 30):
    print("\n")
    print((len(string) % 2)*'-' + '{:-^{width}}'.format(string, width=key()))


def ethanol_readings():
    global mdot, OF, V_initEth, burn_time, P_initEth, density_Eth, V_cham
    density_Eth = 0.78945
    mdot = take_inputs("Mass flow rate (kg/s): ")
    OF = take_inputs("Oxidizer to fuel ratio: ")
    V_initEth = take_inputs("Initial ethanol volume (m^3): ")
    burn_time = take_inputs("Burn time (s): ")
    P_initEth = take_inputs("Initial chamber pressure (Pa): ")
    V_cham = take_inputs("Initial chamber volume (L): ")
    ethanol_calculations()

def ethanol_calculations():
    try:
        mdot_fuel = mdot*(1/(1+OF))
        V_finEth = V_initEth + mdot_fuel*burn_time/density_Eth
        V_finN2 = V_cham - V_finEth
        V_initN2 = V_cham - V_initEth
        P_finEth = P_initEth*V_initN2/V_finN2
        P_diff = P_finEth - P_initEth
        print_header("OUTPUTS")
        print("Final chamber pressure: %.4f Pa" % P_finEth)
        print("Pressure difference: %.4f Pa" % P_diff)
    except (ValueError, ZeroDivisionError):
        print("\n", "Error while attempting to solve. Please enter a valid value"
                    " for every parameter.")
if __name__ == '__main__':
    ethanol_readings()