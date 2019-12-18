# CEA output (.out file) parser
# Jason Chen, Project Caelus, 12/14/2019

import sys
import os
import csv

if __name__ == "__main__":
    csv_filename = "ethanol-75-gox/ethanol-75-gox.csv"
    cea_filename = "ethanol-75-gox/ethanol-75-gox.out"
    delimiter = "THEORETICAL ROCKET PERFORMANCE ASSUMING EQUILIBRIUM"
    with open(csv_filename, mode='w', newline="") as csv_f:
        with open(cea_filename, mode='r') as cea_f:
            cea_lines = cea_f.readlines()
            file_writer = csv.writer(csv_f, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
            unique_rows = set()
            row = ["O/F", "P0 (BAR)", "P1 (BAR)", "T0 (K)", "M (1/n)", "GAMMA", "CSTAR (M/SEC)", "ISP (M/SEC)"]
            dims = len(row)
            for i, line in enumerate(cea_lines):
                if delimiter in line:  # Clear the row and append to a new one
                    assert len(row) == dims
                    if str(row) not in unique_rows:
                        unique_rows.add(str(row))
                        file_writer.writerow(row)
                        print(row)
                    row = []
                    continue
                line = line.strip()
                if "O/F=" in line:
                    temp = line.split()
                    row.append(temp[1])
                if "P, BAR" in line:
                    temp = line.split()
                    row.append(temp[2])
                    row.append(temp[3])
                if "T, K" in line:
                    temp = line.split()
                    row.append(temp[2])
                if "M, (1/n)" in line:
                    temp = line.split()
                    row.append(temp[2])
                if "GAMMAs" in line:
                    temp = line.split()
                    row.append(temp[1])
                if "CSTAR, M/SEC" in line:
                    temp = line.split()
                    row.append(temp[2])
                if "Isp, M/SEC" in line:
                    temp = line.split()
                    row.append(temp[2])
    print("Operation complete. CSV file saved to {}".format(csv_filename))
