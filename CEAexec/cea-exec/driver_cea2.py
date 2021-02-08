# Driver for running the FCEA2m executable
# Jason Chen, Project Caelus, 12/14/2019

import os
import sys
import time
import subprocess
import threading
import pyautogui


def type_with_delay(dir_name: str, delay: int or float):
    time.sleep(delay)
    pyautogui.typewrite(dir_name)
    pyautogui.press("enter")


if __name__ == "__main__":
    print("Please enter the path to (and inluding) the .inp file. Current directory: {}".format(os.getcwd()))
    dir_name = input("Example: \"ethanol-95-n2o/ethanol-95-n2o.inp\": ")
    while os.path.exists(dir_name) == False:
        if dir_name == "0":
            sys.exit(0)
        print("Path invalid. Please try again. Current directory: {}".format(os.getcwd()))
        dir_name = input("Please enter the path to (and including) the .inp file (enter 0 to exit): ")
    dot_index = dir_name.index(".")
    dir_name = dir_name[:dot_index]
    print(dir_name)
    t1 = threading.Thread(target=type_with_delay, args=(dir_name, 0.25), daemon=True)
    t1.start()
    subprocess.call(["FCEA2m.exe"])
    t1.join()
    slash_instances = [index for index, val in enumerate(dir_name) if val == "/"]
    print("Operation complete. {}.out saved to {}.out".format(dir_name[max(slash_instances)+1:], dir_name))
    