# Propulsion

Official propulsion development software for Project Caelus.
Includes MATLAB/Python code for nozzle dimension calculations, tank pressurant characterization and dimensions, Valispace interfacing, CEA use, and more.

## Introduction

This section will detail introductions of the functionality of different scripts and software that can be found in this repository.

   1) CEA (Chemical Equilibrium with Applications) is an open-source NASA thermodynamics library that contains vital propellant combustion data. Its main use for the propulsion team is to provide emperical data for combustion products and characteristics. Namely, given an input propellant combination, its O/F ratio, and chamber pressure, CEA can calculate the exhaust product molecular mass (M), ratio of specific heats (k), combustion temperature, and an estimated ideal C* efficiency. CEA is given in two forms, a Graphical User Interface (`~/CEAgui`), or as a Windows executable (`~/CEAexec`).
   2) `~/cold-flow-data` contains data collected from our various Cold Flow tests. The scripts contained here are for plotting and post-processing.
   3) `~/engine-general` contains a MATLAB script, properties_grapher.m, that plots the output .csv files from ~/CEAexec (namely M, k, C*, and Tc plotted against varying chamber pressures).
   4) `~/fluid-flow-calculations` contains many MATLAB scripts aiming to characterize our the system pressure drop of our system. Currently (as of 01/15/2021), it seems that most of the code can be deprecated besides `pipePressureLossCalc.m`, which accurately calculates the raw pressure drop due to only pipe length and roughness. This script was used in the April 2020 edition of the Aphlex 1B documentation. For pressure drops due to valves, only simple algebra is required to sum all valve Cv's from the propellant tank to the injector. However, a script should be developed that computes all tank/system characteristics (initial and final ullage/propellant volume, initial and final tank pressure, the net system pressure drop, and pressure profiles at every point in the system) using some input parameters (chamber pressure, mass flow rate, tank volume, pipe length/diameter/roughness, total Cv, injector pressure drop percentage).
   5) `~/nozzle-calculations` contains scripts for automated nozzle characterization. `nozzle_calc.py` computes the physical nozzle dimensions (e.g. throat and exit radius) and performance characteristics (e.g. effective exhaust velocity) using input thermodynamic properties obtained from CEA and other engine parameters. `nozzle_calc_mod.py` does the same thing, except with a 8:1 contraction ratio instead of 4:1. `moc_nozzle.m` is a vigorously researched and written script that automates the creation of a minimum-length supersonic nozzle using the Method of Characteristics (MOC) in MATLAB. Given k, exit Mach number, and throat radius, it creates a .csv file containing the Cartesian coordinates of all points that characterize the MOC nozzle contour. This .csv file can then be imported into Fusion 360 or any other CAD software. It is recommended that new Caelus members try to understand and/or derive `moc_nozzle.m` for deeper intuition of high-speed flows.
   6) `~/open-rocket` contains old experimental files for testing the aerodynamics of our Callisto 1 vehicle using the open-source software, OpenRocket. Most of this data can be deprecated.
   7) `~/part-calculations` contains miscellaneous/old calculation files. Can be deprecated.
   8) `~/pdf` contains PDF files of important research papers that we have used as technical references.
   9) `~/simulink` contains miscellaneous Simulink files. These were originally used to try characterizing our plumbing system, though we've since found better methods. Can be deprecated, or used as future reference when we use Simulink for classical control purposes.
   10) `~/solid-motors` contains data for solid propellant rocket motors. Can be deprecated.
   11) `~/system-simulations` contains graphs of system simulation data for our Aphlex 1B nitrous oxide system. The source code can be found at <https://github.com/JayChen35/PropSim>, along with further technical explaination.

## Usage, Installation, and Procedures

### CEAgui/CEAexec

`~/CEAgui` should not be run directly after cloning this repository (avoid pushing to this repository if you have changes to the CEAgui folder). The first step should always be copy and pasting the CEAgui folder into another local working directory. Once CEAgui is in another location, execution should be simple: run `CEAexec-win.bat`. *Make sure you run the .bat (Windows Batch File) version of CEAexec-win.* Of course, this implies that CEAgui only works on a Windows operating system. For further instructions on how to use CEAgui in a technical lens, try this Youtube tutorial: <https://www.youtube.com/watch?v=RbG2n6ClaCs>.

`~/CEAexec` has identical capabilities as CEAgui, but in the form of an interfaceable Windows executable (.exe). There are already Python scripts that will automate the iteration through different O/F ratios and chamber pressures for CEAexec. They can be found inside the `~/CEAexec` directory. *Make sure you run the scripts in this exact order:* 1) `input_generator.py`, `driver_cea2.py`, `output_parser.py`. After the completion of `output_parser.py`, a directory containing .inp, .out, and .csv files should be found with a name corresponding to the parameters that were imputted (e.g. 95% ethanol with nitrous oxide will be titled "ethanol-95-n2o"). The .csv file will be especially useful for MATLAB plotting scripts found elsewhere in this repository.

### Notes

All Python scripts are compatible with Python 3.6+.
README.md was last editted on 01/15/2021 by Jason Chen (2021).
