import operator

minimumValue = 30 # inches
maximumValue = 42 # inches

parts = []
file = open("parts.txt", "r")
for part in file.readlines():
   parts.append(float(part.rstrip('\n')))
file.close()

print(sum(parts))

lengthToCount = dict()
for length in range(minimumValue, maximumValue+2, 2):
   count = 0
   for part in parts:
      count += int(part//length)
   lengthToCount[length] = count

print(lengthToCount)
# print("Maximum:", max(lengthToCount.iteritems(), key=operator.itemgetter(1))[0])

