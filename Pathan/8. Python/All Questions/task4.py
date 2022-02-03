import csv
import matplotlib.pyplot as plt


years = []  # stores years in the csv
Canada = []  # stores expectency of canada
Italy = []  # stores expectency of italy
NewZealand = []  # stores expectency of new zealand
Spain = []  # stores expectency of spain
with open('HealthyLifeExpectancy.csv', 'r') as file:  # open file to read
    reader = csv.reader(file)  # get data from file
    i = 0  # count of lines
    for row in reader:  # iterate over all lines
        i += 1  # increment counter
        print(row)  # print row
        if(i > 1):
            years.append(int(row[0]))  # add year to list
            Canada.append(float(row[1]))  # add expectancy to list of canada
            Italy.append(float(row[2]))  # add expectancy to list of Italy
            # add expectancy to list of newzealand
            NewZealand.append(float(row[3]))
            Spain.append(float(row[4]))  # add expectancy to list of spain


print(years)  # print list of year
print(Canada)  # print list of expectancy of canada
print(Italy)  # print list of expectancy of italy
print(NewZealand)  # print list of expectancy of newzealand
print(Spain)  # print list of expectancy of spain


# plot lines
plt.plot(years, Canada, label="Canada",  color="red")  # plot first line
plt.plot(years, Italy, label="Italt", color="green")  # plot second  line
plt.plot(years, NewZealand, label="New Zealand",
         color="blue")  # plot third  line
plt.plot(years, Spain, label="Spain", color="black")  # plot fourth line
plt.xlabel("Year")  # label for x axis
plt.ylabel("Country")  # label for y axis
plt.legend()
plt.show()
