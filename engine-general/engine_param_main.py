from cea import cea_main
from nozzle import nozzle_main
from injector import injector_main
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
    vars["frozen"] = "frozen nfz=1" if bool(vars["frozen"]) else "equilibrium"
    return vars


def print_header(string, key=lambda: 30):
    """
    Provides an easy way to print out a header.
    :param string: The header as a string.
    :param key: Length of the message.
    """
    print("\n")
    print((len(string) % 2)*'-' + '{:-^{width}}'.format(string, width=key()))


if __name__ == "__main__":
    vars = take_all_inputs()
    cea_vars = cea_main(vars)
    nozzle_vars = nozzle_main(vars, cea_vars)
    injector_vars = injector_main(vars, cea_vars, nozzle_vars)
