
"""
-------------------------------------------------------------------------------------
ALL CALCULATIONS ARE DONE IN STANDARD IMPERIAL (SI) UNITS, WITH TEMPERATURE IN KELVIN.
ANGLES IN DEGREES.
-------------------------------------------------------------------------------------

INPUTS:
    - mdot = Mass flow rate, kg/sec
    - OF = Oxidizer to fuel ratio, dimensionless
    - rho_f = Fuel density, kg/m^3
    - rho_o = Oxidizer density, kg/m^3
    - P0, Chamber pressure, Pa
    - delta_p = Pressure drop across injector, % (of chamber pressure)
    - d_o = Starting diameter of oxidizer orifice, mm (1.58)
    - Cd_o = Discharge coefficient of oxidizer orifice, dimensionless (0.9)
    - d_f = Starting diameter of fuel orifice, mm (1.00)
    - Cd_f = Discharge coefficient of fuel orifice, dimensionless (0.88)
    - imp_angle = Impingement angle, degrees (60)

OUTPUTS:
    - n_o = Number of oxidizer orifices
    - d_o = Diameter of oxidizer orifice, mm
    - a_o = Area of oxidizer orifice, mm
    - L_jet_o = Oxidizer jet length, mm
    - L_poi_o = Oxidizer point of impigement distance, mm
    - d_com_o = Oxidizer orifice distance (combustor), mm
    - d_man_o = Oxidizer orifice distance (manifold), mm

    - n_f = Number of fuel orifices
    - d_f = Diameter of fuel orifice, mm
    - a_f = Area of fuel orifice, mm
    - L_jet_f = Fuel jet length, mm
    - L_poi_f = Fuel point of impigement distance, mm
    - d_com_f = Oxidizer fuel distance (combustor), mm
    - d_man_f = Oxidizer fuel distance (manifold), mm

    - L_inj = Injector plate thickness

"""

# Imports
import numpy as np

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
                    outarray.append(float(line.strip()))
                    # count = 0
                    # for char in line:
                        # if char == (":"):
                        #     out = line[count+1:]
                        #     outarray.append(float(out))
                        #     break
                        # count += 1
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

    global mdot, mdot_o, mdot_f, OF, rho_f, rho_o, P0, delta_p, og_d_o, Cd_o, og_d_f, Cd_f, imp_angle
    mdot = take_input("Mass flow rate (kg/sec): ")
    OF = take_input("Oxidizer to fuel ratio: ")
    mdot_o = mdot * OF/(OF+1)
    mdot_f = mdot * 1/(OF+1)
    rho_f = take_input("Fuel Density (kg/m^3): ")
    rho_o = take_input("Oxidizer Density (kg/m^3): ")
    P0 = take_input("Chamber Pressure (Pa): ")
    delta_p = take_input("Pressure drop across injector (%): ")
    og_d_o = take_input("Statrting diameter of oxidizer orifice (mm): ")
    Cd_o = take_input("Discharge coefficient of oxidizer orifice: ")
    og_d_f = take_input("Starting diameter of fuel orifice (mm): ")
    Cd_f = take_input("Discharge coefficient of fuel orifice:  ")
    imp_angle = take_input("Impingement angle (degrees): ")
    calculate()

def calc_text():
    """
    Defines user parameters from text file and calls a calculation.
    """
    global mdot, mdot_o, mdot_f, OF, rho_f, rho_o, P0, delta_p, og_d_o, Cd_o, og_d_f, Cd_f, imp_angle
    mdot = outarray[0]
    OF = outarray[1]
    mdot_o = mdot * OF/(OF+1)
    mdot_f = mdot * 1/(OF+1)
    rho_f = outarray[2]
    rho_o = outarray[3]
    P0 = outarray[4]
    delta_p = outarray[5]
    og_d_o = outarray[6]
    Cd_o = outarray[7]
    og_d_f = outarray[8]
    Cd_f = outarray[9]
    imp_angle = outarray[10]
    calculate()

def calculate():
    """
    Attempts to calculate and print values.
    """
    try:  # Attempt to calculate values
        M = 1.6
        jet_LD = 6
        orifice_LD = 7

        diam_ratio = np.sqrt(M * (((rho_o/rho_f)*(mdot_o/mdot_f)**2)**0.7))
        
        mdot_o_orifice = Cd_o * (np.pi * ((og_d_o/2) * 0.001)**2) * np.sqrt(2 * rho_o * P0 * 0.25)
        mdot_f_orifice = Cd_f * (np.pi * ((og_d_f / 2) * 0.001)**2) * np.sqrt(2 * rho_f * P0 * 0.25)
        
        n_o = mdot_o / mdot_o_orifice
        n_f = mdot_f / mdot_f_orifice
        
        n_o = round(n_o) if round(n_o) % 2 == 0 else round(n_o) + 1
        n_f = round(n_f) if round(n_o) % 2 == 0 else round(n_f) + 1

        d_o = 2 * np.sqrt(mdot_o/(Cd_o * n_o * np.pi * np.sqrt(2 * rho_o * P0 * delta_p/100))) * 1000
        d_f = 2 * np.sqrt(mdot_f/(Cd_f * n_f * np.pi * np.sqrt(2 * rho_f * P0 * delta_p/100))) * 1000

        a_o = np.pi * (d_o/2)**2
        a_f = np.pi * (d_f/2)**2

        L_jet_o = jet_LD * d_o
        L_jet_f = jet_LD * d_f

        print(imp_angle)
        L_poi_o = L_jet_o * np.cos(np.deg2rad(imp_angle/2))
        L_poi_f = L_jet_f * np.cos(np.deg2rad(imp_angle/2))
        
        L_inj = orifice_LD * max(d_o, d_f) * np.cos(np.deg2rad(imp_angle / 2))

        d_com_f = 2 * L_jet_f * np.sin(np.deg2rad(imp_angle / 2))
        d_com_o = 2 * L_jet_o * np.sin(np.deg2rad(imp_angle / 2))
        d_man_f = (d_com_o/L_poi_o) * (L_inj + L_poi_o)
        d_man_o = (d_com_f/L_poi_f) * (L_inj + L_poi_f)


        print_header("INPUTS")
        print("Mass Flow Rate: ", mdot, "kg/sec")
        print("O/F Ratio: ", OF)
        print("Fuel Density: ", rho_f, "kg/m^3")
        print("Oxidizer Density: ", rho_o, "kg/m^3")
        print("Chamber Pressure: ", P0, "Pa")
        print("Pressure Drop Across Injector: ", delta_p, "% of P0")
        print("Starting Oxidizer Oririce Diameter: ", og_d_o, "mm")
        print("Oxidizer Orifice Discharge Coefficient: ", Cd_o)
        print("Starting Fuel Oririce Diameter: ", og_d_f, "mm")
        print("Oxidizer Fuel Discharge Coefficient: ", Cd_f)
        print("Impingement Angle: ", imp_angle, "deg")

        print_header("OUTPUTS")
        print("Injector plate thickness: ", L_inj, "mm")

        print("\nOXIDIZER DATA:")
        print("Number of oxidizer orifices: ", round(n_o, 3))
        print("Diameter of oxidizer orifice:", round(d_o, 3), "mm")
        print("Area of oxidizer orifice: ", round(a_o, 3), "mm^2")
        print("Oxidizer jet length: ", round(L_jet_o, 3), "mm")
        print("Oxidizer impingement distance: ", round(L_poi_o, 3), "mm")
        print("Oxidizer orifice distance (combustor): ", round(d_com_o, 3), "mm")
        print("Oxidizer orifice distance (manifold):", round(d_man_o, 3), "mm")

        print("\nFUEL DATA:")
        print("Number of fuel orifices: ", round(n_f, 3))
        print("Diameter of fuel orifices: ", round(d_f, 3), "mm")
        print("Area of fuel orifice: ", round(a_f, 3), "mm^2")
        print("Fuel jet length: ", round(L_jet_f, 3), "mm")
        print("Fuel point of impingement distance: ", round(L_poi_f, 3), "mm")
        print("Fuel orifice distance (combustor): ", round(d_com_f, 3), "mm")
        print("Fuel orifice distance (manifold): ", round(d_man_f, 3), "mm")

    except (ValueError, ZeroDivisionError):  # Exception thrown
        print("\n", "Error while attempting to solve. Please enter a valid value"
              " for every parameter.")

if __name__ == "__main__":
    prompt()
