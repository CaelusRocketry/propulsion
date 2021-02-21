"""
INPUTS:
    CEAgui
 
    Nozzle Calc

    Injector
        
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

#TODO document bruv






from cea import cea_main
from nozzle import nozzle_main
from injector import injector_main
from cea import get_exit_pressure
# from propsim import propsim_main

def take_all_inputs():
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


def print_header(string, key=lambda: 30):
    """
    Provides an easy way to print out a header.
    :param string: The header as a string.
    :param key: Length of the message.
    """
    print("\n")
    print((len(string) % 2)*'-' + '{:-^{width}}'.format(string, width=key()))


if __name__ == "__main__":
    temp = take_all_inputs()
    vars = temp[0]
    ceagui_name = temp[1]
    cea_vars = cea_main(vars, ceagui_name)
    nozzle_vars = nozzle_main(cea_vars)
    injector_vars = injector_main(nozzle_vars)
    for key in injector_vars:
        print(f"{key} = {injector_vars}")
#TODO format outputs