# Supersonic Nozzle Design Calculation Program
# Created by Jason Chen, Project Caelus
# Thomas Jefferson High School for Science and Technology
# Developed on April 22nd, 2018

"""

This program generates important parameters in a conical supersonic converging-diverging
nozzle from certain user inputs. Below is a full list of this program's capabilities and
key thermodynamic assumptions. Many input parameters can be obtained from NASA's CEA program
(Chemical Equilibrium with Applications), which is available freely available to the
public for download here (https://www.grc.nasa.gov/www/CEAWeb/).


-------------------------------------------------------------------------------------
ALL CALCULATIONS ARE DONE IN STANDARD IMPERIAL (SI) UNITS, WITH TEMPERATURE IN KELVIN.
ANGLES IN DEGREES.
-------------------------------------------------------------------------------------


CALCULATION ASSUMPTIONS:
    1) Flow maintains equilibrium at the local pressure and enthalpy level (reversible).
    2) No heat transfer across gas-enclosure walls; closed system (adiabatic).
    3) By definition, the flow is isentropic due to assumptions 1 and 2.
    4) Flow composition is considered frozen (tends to underestimate performance by 1-4%).
    5) Working fluid obeys the perfect gas law.
    6) All species of the working fluid in the flow is gaseous.
    7) Wall friction is negligible and all boundary layer effects are ignored.
    8) There are no shock waves or other discontinuities within the nozzle flow.
    9) Propellant mass flow rate is constant and steady.
    10) Expansion of the working fluid is uniform and steady; no significant turbulence.
    11) All exhaust gases travel with a velocity parallel to the nozzle axis.
    12) Gas velocity, pressure, temperature, & density are all uniform across any section
        perpendicular to the nozzle axis.
    13) Nozzle dimensions assume an optimum divergence half-angle of 15 degrees, and an
        optimum convergence half-angle of 45 degrees.
    14) Contraction ratio (cross-sectional area of the chamber/area of the throat) of 8.

INPUTS:
    - F = Desired thrust, N
    - P0 = Chamber pressure, Pa
    - P3 = Ambient pressure, Pa
    - O/F = Oxidizer to fuel ratio, dimensionless
    - T0 = Combustion chamber temperature, K
    - M = Molecular mass of the gas, kg/mol
    - k = Ratio of specific heats, cp/cv, dimensionless
    - L* = Characteristic chamber length, m

OUTPUTS:
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

"""

# Imports
from math import sqrt, tan, radians, pi


def prompt():
    global outarray
    print("\n ----------------------------------------------------------------------",
          "\n", "Take parameters through keyboard inputs or from text file (input.txt)?",
          "\n ----------------------------------------------------------------------")
    prompt = input("Enter INPUT or FILE: ")
    if(prompt == ("INPUT")):
        print("\n")
        calc_readings()
    elif(prompt == ("FILE")):
        outarray = []
        try:
            with open("input.txt") as file:
                line = file.readline().strip()
                while line:
                    count = 0
                    for char in line:
                        if char == (":"):
                            out = line[count+1:]
                            outarray.append(float(out))
                            break
                        count += 1
                    line = file.readline().strip()
            file.close()
            calc_text()
        except IOError:
            print("\n", "Error reading file. Please make sure input.txt exists in the"
                  " correct directory.")
        except ValueError:
            print("\n", "Error while attempting to solve. Please make sure every input"
                        " is a numeric value and/or has inputs.")
    else:
        print("\n", "Invalid! Please enter INPUT or FILE to select your desired"
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
    print((len(string) % 2)*'-' + '{:-^{width}}'.format(string, width=key()))


def calc_readings():
    """
    Defines user parameters from user input and calls a calculation.
    """
    global F, P0, P3, OF, T0, M, k, Lstar
    F = take_input("Desired thrust (N): ")
    P0 = take_input("Chamber pressure (Pa): ")
    P3 = take_input("Ambient pressure at specific altitude (Pa): ")
    OF = take_input("Oxidizer to fuel ratio: ")
    T0 = take_input("Combustion chamber temperature (K): ")
    M = take_input("Gas molecular mass (kg/mol): ")
    k = take_input("Ratio of specific heats (cp/cv): ")
    Lstar = take_input("Characteristic chamber length (L*, in meters): ")
    calculate()

def calc_text():
    """
    Defines user parameters from text file and calls a calculation.
    """
    global F,P0,P3,OF,T0,M,k,Lstar
    F = outarray[0]
    P0 = outarray[1]
    P3 = outarray[2]
    OF = outarray[3]
    T0 = outarray[4]
    M = outarray[5]
    k = outarray[6]
    Lstar = outarray[7]
    calculate()

def calculate():
    """
    Attempts to calculate and print values.
    """
    try:  # Attempt to calculate values
        R = (8314.3 / M)
        PR = (P3 / P0)
        AR = (((k + 1) / 2) ** (1 / (k - 1))) * ((P3 / P0) ** (1 / k)) * (
            sqrt(((k + 1) / (k - 1)) * (1 - ((P3 / P0) ** ((k - 1) / k)))))
        ER = 1 / AR
        Tt = (2 * T0) / (k + 1)
        v2 = sqrt((2 * k / (k - 1)) * ((R) * T0) * (1 - ((P3 / P0) ** ((k - 1) / k))))
        mdot = F / v2
        mdot_fuel = (mdot / (OF + 1))
        mdot_oxidizer = (mdot / (OF + 1)) * OF
        Isp = F / (mdot * 9.80655)
        Te = T0 / ((P0 / P3) ** ((k - 1) / k))
        Mnum = (v2 / (sqrt(k * (R) * (Te))))
        At = ((mdot) * (sqrt((k * R * T0)))) / (k * P0 * (sqrt(((2 / (k + 1)) ** ((k + 1) / (k - 1))))))
        Ae = ER * At
        Rt = sqrt(At / pi)
        Re = sqrt(Ae / pi)
        Ac = At * 8
        Rc = sqrt((Ac) / pi)
        Lc = ((At) * Lstar) / (Ac)
        Ldn = ((Re) - (Rt)) / (tan(radians(15)))
        Lcn = ((Rc) - (Rt)) / (tan(radians(45)))

        print_header("INPUTS")
        print("Thrust: ", F, "N")
        print("Chamber pressure: ", P0, "Pa")
        print("Ambient pressure: ", P3, "Pa")
        print("O/F ratio:", OF)
        print("Combustion temperature:", T0, "K")
        print("Molecular mass:", M, "kg/mol")
        print("Gamma:", k)
        print("Characteristic chamber length:", Lstar, "m")

        print_header("OUTPUTS")
        print("Specific impulse (at altitude): ", "%.4f" % Isp, "sec")
        print("Throat temperature: ", "%.4f" % Tt, "K")
        print("Effective exhaust velocity: ", "%.4f" % v2, "m/sec")
        print("Mass flow rate: ", "%.4f" % mdot, "kg/sec")
        print("Mass flow rate (oxidizer): ", "%.4f" % mdot_oxidizer, "kg/sec")
        print("Mass flow rate (fuel): ", "%.4f" % mdot_fuel, "kg/sec")
        print("Exit temperature: ", "%.4f" % Te, "K")
        print("Exit Mach number: ", "%.4f" % Mnum)
        print("Pressure ratio: ", "%.4f" % PR)
        print("Expansion ratio: ", "%.4f" % ER)

        print_header("NOZZLE DIMENSIONS")
        print("Area of the throat: ", "%.7f" % At, "m^2")
        print("Area of the exit: ", "%.7f" % Ae, "m^2")
        print("Throat radius: ", "%.7f" % Rt, "m")
        print("Exit radius: ", "%.7f" % Re, "m")
        print("Chamber radius: ", "%.7f" % Rc, "m")
        print("Chamber length: ", "%.7f" % Lc, "m")
        print("Length of the diverging nozzle: ", "%.7f" % Ldn, "m")
        print("Length of the converging nozzle: ", "%.7f" % Lcn, "m")

    except (ValueError, ZeroDivisionError):  # Exception thrown
        print("\n", "Error while attempting to solve. Please enter a valid value"
              " for every parameter.")

if __name__ == "__main__":
    prompt()
