import csv
from os import remove
import matplotlib.pyplot as plt
import numpy as np


list = []
with open('2020_car_sale.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        thisdict = {
            "car_model": row[0],
            "contract_date": row[1],
            "car_brand": row[2],
            "State": row[3],
            "car_safety_rating": row[4],
            "amount": row[5],
            "color": row[6],
        }
        list.append(thisdict)


print("Total Number of deals : " + str(len(list)-1))


def getAmountInMonth(brand):

    thiamon = {
        "Januaury": 0,
        "Feburary": 0,
        "March": 0,
        "April": 0,
        "May": 0,
        "June": 0,
        "July": 0,
        "August": 0,
        "September": 0,
        "October": 0,
        "November": 0,
        "December": 0,
    }
    for li in list:
        str = li["contract_date"]
        if str[-4:] == "2020":
            if(str[1] == '/'):
                if(str[:1] == '1'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["Januaury"] += int(s)
                elif(str[:1] == '2'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["Feburary"] += int(s)
                elif(str[:1] == '3'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["March"] += int(s)
                elif(str[:1] == '4'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["April"] += int(s)
                elif(str[:1] == '5'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["May"] += int(s)
                elif(str[:1] == '6'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["June"] += int(s)
                elif(str[:1] == '7'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["July"] += int(s)
                elif(str[:1] == '8'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["August"] += int(s)
                elif(str[:1] == '9'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["September"] += int(s)
            else:
                if(str[:2] == '10'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["October"] += int(s)
                elif(str[:2] == '11'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["November"] += int(s)
                elif(str[:2] == '12'):
                    s = li["amount"]
                    if s == "sales amount ($)":
                        continue
                    s = s[:-4] + s[(-4+1):]
                    if li["State"] == brand:
                        thiamon["December"] += int(s)
    return thiamon


def get_Amount(state):
    most_amount = 0
    # traverse for all elements
    s = ""
    for li in list:
        str = ""
        str = li["amount"]
        if str == "sales amount ($)":
            continue
        elif (li["State"] == state):
            str = str[:-4] + str[(-4+1):]
            most_amount = most_amount + int(str)
    return most_amount


def get_AmountByDate():
    most_amount = 0
    # traverse for all elements
    s = ""
    for li in list:
        str = ""
        s = li["amount"]
        str = li["contract_date"]
        if s == "sales amount ($)":
            continue
        elif (str[0] == '4'):
            s = s[:-4] + s[(-4+1):]
            most_amount = most_amount + int(s)
    return most_amount


def get_percentage(brand):
    most_amount = 0
    for li in list:
        str = ""
        s = li["amount"]
        str = li["car_brand"]
        if s == "sales amount ($)":
            continue
        elif (str == brand):
            s = s[:-4] + s[(-4+1):]
            most_amount = most_amount + int(s)

    return most_amount


unique_list = []

# traverse for all elements
for li in list:
    # for x in li:
    # print(li["car_model"])
    if li["car_model"] not in unique_list:
        unique_list.append(li["car_model"])

print("Number of different Car Models : " + str(len(unique_list)-1))


unique_brand = []

# traverse for all elements
for li in list:
    # for x in li:
    # print(li["car_model"])
    if li["car_brand"] not in unique_brand:
        unique_brand.append(li["car_brand"])

print("Number of different Car Brands : " + str(len(unique_brand)-1))


unique_rating = []

# traverse for all elements
for li in list:
    # for x in li:
    # print(li["car_model"])
    if li["car_safety_rating"] not in unique_rating:
        unique_rating.append(li["car_safety_rating"])


print("Number different of Car Safty Rating: " + str(len(unique_rating)-1))


unique_color = []

# traverse for all elements
for li in list:
    if li["color"] not in unique_color:
        unique_color.append(li["color"])

print("Number different of Car color: " + str(len(unique_color)-1))


unique_state = []
for li in list:
    if li["State"] not in unique_state:
        unique_state.append(li["State"])


sale_amount = 0

# traverse for all elements
for li in list:
    str = li["amount"]
    if str == "sales amount ($)":
        continue
    str = str[:-4] + str[(-4+1):]
    sale_amount = sale_amount + int(str)

print(f"Total Sale Amount: {sale_amount}")

print("\n===========================================\n")


max = 0
for li in list:
    if(get_Amount(li["State"]) > max):
        max = get_Amount(li["State"])

print(f"Most number of cars sold ({max}) in Florida")


max = 0
for li in list:
    if(get_AmountByDate() > max):
        max = get_AmountByDate()

print(f"Maximum number of sales ({max}) was in April ")


percentageList = []
percentageListBrand = []
amountPerList = []

for ubrand in unique_brand:
    amount = get_percentage(ubrand)
    amountPerList.append(amount)
    a = amount/sale_amount * 100
    if(a >= 4):
        percentageList.append(a)
        percentageListBrand.append(ubrand)


sum = 0
perBrand = []
for per, bran in zip(percentageList, unique_brand):
    if(per >= 4):
        sum = sum + per
        print(f"{bran}:  {per: .2f}%")
        perBrand.append(per)
print(f"Other: {100-sum: .2f}%")
other = 100 - sum
percentageList.append(other)
percentageListBrand.append("Other")


unique_stateAmount = []
for count in unique_state:
    am = get_Amount(count)
    # if(am > 0):
    unique_stateAmount.append(am)


Happiness_Index = []
for uniAmt in unique_stateAmount:
    if(uniAmt > 0):
        Happiness_Index.append(uniAmt)

print(Happiness_Index)
city = ["Texas", "California", "Florida", "Ohio", "Nevada"]
pos = np.arange(len(city))

plt.bar(pos, Happiness_Index, color='blue', edgecolor='black')
plt.xticks(pos, city)
plt.xlabel('State', fontsize=16)
plt.ylabel('Amount of sale', fontsize=16)
plt.title('Ammount of sale in different State', fontsize=20)

plt.show()


# Data to plot
labelss = "Chevrolet", "Toyota", "Ford", "Nissan", "Honda", "GMC", "Mazda", "Hyunda", "Kia", "Dodge", "Others"
sizes = [10.114782194740618, 9.27856800599305, 9.133257799067342, 5.946010669938903,  5.635617331556334, 5.530819661149936,
         5.02976930604361, 4.69773125308992, 4.378720212312544, 4.1033098690226, 36.15141369708515]
colors = ['gold', 'yellowgreen', 'lightcoral', 'lightskyblue']
explode = (0.1, 0, 0, 0)  # explode 1st slice

# Plot
plt.pie(sizes, labels=labelss, colors=colors,
        autopct='%1.1f%%', shadow=True, startangle=140)

plt.axis('equal')
plt.title('Percentage of sale by different car brands', fontsize=20)
plt.show()


thismonths = {
    "Januaury": 0,
    "Feburary": 0,
    "March": 0,
    "April": 0,
    "May": 0,
    "June": 0,
    "July": 0,
    "August": 0,
    "September": 0,
    "October": 0,
    "November": 0,
    "December": 0,
}


for li in list:
    str = li["contract_date"]
    if str[-4:] == "2020":
        if(str[1] == '/'):
            if(str[:1] == '1'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["Januaury"] += int(s)
            elif(str[:1] == '2'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["Feburary"] += int(s)
            elif(str[:1] == '3'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["March"] += int(s)
            elif(str[:1] == '4'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["April"] += int(s)
            elif(str[:1] == '5'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["May"] += int(s)
            elif(str[:1] == '6'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["June"] += int(s)
            elif(str[:1] == '7'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["July"] += int(s)
            elif(str[:1] == '8'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["August"] += int(s)
            elif(str[:1] == '9'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["September"] += int(s)
        else:
            if(str[:2] == '10'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["October"] += int(s)
            elif(str[:2] == '11'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["November"] += int(s)
            elif(str[:2] == '12'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                thismonths["December"] += int(s)


mm = []
mmm = []
for month in thismonths:
    mm.append(month)
    mmm.append(thismonths[month])


plt.plot(mm, mmm)
plt.title('Amount of sale in year 2020')
plt.xlabel('months')
plt.ylabel('Amount of sale')
plt.show()


thismonths = getAmountInMonth("Texas")
m1 = []
mm1 = []
for month in thismonths:
    m1.append(month)
    mm1.append(thismonths[month])


thismonths = getAmountInMonth("California")
m2 = []
mm2 = []
for month in thismonths:
    m2.append(month)
    mm2.append(thismonths[month])

thismonths = getAmountInMonth("Florida")
m3 = []
mm3 = []
for month in thismonths:
    m3.append(month)
    mm3.append(thismonths[month])


thismonths = getAmountInMonth("Ohio")
m4 = []
mm4 = []
for month in thismonths:
    m4.append(month)
    mm4.append(thismonths[month])


thismonths = getAmountInMonth("Nevada")
m5 = []
mm5 = []
for month in thismonths:
    m5.append(month)
    mm5.append(thismonths[month])


plt.plot(m1, mm1)
plt.plot(m2, mm2)
plt.plot(m3, mm3)
plt.plot(m4, mm4)
plt.plot(m5, mm5)
plt.title('Amount of sale in diffrent months in each state')
plt.xlabel('months')
plt.ylabel('Amount of sale')
plt.show()
