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
        discontinuities within the nozzle flow. Expanding sections are modeled as a
        continuous series of expansion waves, each turning the flow an infinitestimal
        amount along nozzle contour.
    9) By definition, characteristics are curves within the flow in which velocity is
        continuous but the first derivative of velocity is discontinuous.
    10) Expansion of the working fluid is uniform and steady; no significant turbulence.
    11) All exhaust gases travel with a velocity parallel to the nozzle axis.
    12) Gas velocity, pressure, temperature, & density are all uniform across any section
        perpendicular to the nozzle axis.

INPUTS:
    - M = Desired exit Mach number, dimensionless
    - Rt = Throat radius, mm
    - k = Ratio of specific heats, cp/cv, dimensionless

OUTPUTS:
    - Set of (x,y) points representing the diverging nozzle contour.
    - Excel document containing the afformentioned points.
    - Plots of the characteristic lines generated.

"""
