import csv
import matplotlib.pyplot as plt


years = []
Canada = []
Italy = []
NewZealand = []
Spain = []
with open('HealthyLifeExpectancy.csv', 'r') as file:
    reader = csv.reader(file)
    i = 0
    for row in reader:
        i += 1
        print(row)
        if(i > 1):
            years.append(int(row[0]))
            Canada.append(float(row[1]))
            Italy.append(float(row[2]))
            NewZealand.append(float(row[3]))
            Spain.append(float(row[4]))


print(years)
print(Canada)
print(Italy)
print(NewZealand)
print(Spain)


# plot lines
plt.plot(years, Canada, label="Canada",  color="red")
plt.plot(years, Italy, label="Italt", color="green")
plt.plot(years, NewZealand, label="New Zealand", color="blue")
plt.plot(years, Spain, label="Spain", color="black")
plt.xlabel("Year")
plt.ylabel("Country")
plt.legend()
plt.show()
