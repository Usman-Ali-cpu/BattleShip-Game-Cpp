import numpy as np
import csv
from os import remove
import matplotlib.pyplot as plt


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

# for li in list:
#     for x in li:
#         print(li[x])


print("Total Number of deals : " + str(len(list)-1))


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

        #     #         print(li[x])
        #     # check if exists in unique_list or not

        # # print list
        # for x in unique_list:
        #     print x,
print("Number of different Car Models : " + str(len(unique_list)-1))


unique_brand = []

# traverse for all elements
for li in list:
    # for x in li:
    # print(li["car_model"])
    if li["car_brand"] not in unique_brand:
        unique_brand.append(li["car_brand"])

        #     #         print(li[x])
        #     # check if exists in unique_list or not

        # # print list
        # for x in unique_list:
        #     print x,
print("Number of different Car Brands : " + str(len(unique_brand)-1))


unique_rating = []

# traverse for all elements
for li in list:
    # for x in li:
    # print(li["car_model"])
    if li["car_safety_rating"] not in unique_rating:
        unique_rating.append(li["car_safety_rating"])

        #     #         print(li[x])
        #     # check if exists in unique_list or not

        # # print list
        # for x in unique_list:
        #     print x,
print("Number different of Car Safty Rating: " + str(len(unique_rating)-1))


unique_color = []

# traverse for all elements
for li in list:
    # for x in li:
    # print(li["car_model"])
    if li["color"] not in unique_color:
        unique_color.append(li["color"])

print("Number different of Car color: " + str(len(unique_color)-1))


unique_state = []
for li in list:
    if li["State"] not in unique_state:
        unique_state.append(li["State"])

# print("Number different of Car color: " + str(len(unique_color)-1))


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
# print("Max is : " + str(max))


max = 0
for li in list:
    if(get_AmountByDate() > max):
        max = get_AmountByDate()

print(f"Maximum number of sales ({max}) was in April ")


percentageList = []
percentageListBrand = []

for ubrand in unique_brand:
    amount = get_percentage(ubrand)
    a = amount/sale_amount * 100
    if(a >= 4):
        percentageList.append(a)
        percentageListBrand.append(ubrand)


sum = 0
perBrand = []
for per, bran in zip(percentageList, unique_brand):
    if(per >= 4):
        sum = sum + per
        print(f"{bran}:  {per: .2f}")
        perBrand.append(per)
print(f"Other: {100-sum: .2f}")
other = 100 - sum
percentageList.append(other)
percentageListBrand.append("Other")


# fig = plt.figure()
# ax = fig.add_axes([0, 0, 1, 1])
# langs = ['C', 'C++', 'Java', 'Python', 'PHP']
# students = [23, 17, 35, 29, 12]
# ax.bar(langs, students)
# plt.show()


unique_stateAmount = []
for count in unique_state:
    am = get_Amount(count)
    unique_stateAmount.append(am)


fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
# langs = ['C', 'C++', 'Java', 'Python', 'PHP']
# students = [23, 17, 35, 29, 12]
ax.bar(unique_state, unique_stateAmount)
ax.set_title('Amount of Sale in different State')
ax.set_ylabel('Amount of Sales')
ax.set_xlabel('States')

# plt.show()


# X = [1 3 0.5 2.5 2]
# plt.pie(percentageList)
# plt.show()


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


# plt.plot(mm, mmm)
# plt.title('Amount of sale in year 2020')
# plt.xlabel('months')
# plt.ylabel('Amount of sale')
# plt.show()


thismonth = {
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


statemonths = {
    "Texas": thismonths,
    "California": thismonths,
    "Florida": thismonths,
    "Ohio": thismonths,
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
                if(li["State"] == "California"):
                    statemonths["California"]["Januaury"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["Januaury"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["Januaury"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["Januaury"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["Januaury"] += int(s)

                #thismonths["Januaury"] += int(s)

            elif(str[:1] == '2'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["Feburary"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["Feburary"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["Feburary"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["Feburary"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["Feburary"] += int(s)

                #thismonths["Feburary"] += int(s)
            elif(str[:1] == '3'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["March"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["March"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["March"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["March"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["March"] += int(s)

            elif(str[:1] == '4'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["April"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["April"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["April"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["April"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["April"] += int(s)
            elif(str[:1] == '5'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["May"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["May"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["May"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["May"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["May"] += int(s)
            elif(str[:1] == '6'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["June"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["June"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["June"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["June"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["June"] += int(s)
            elif(str[:1] == '7'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["July"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["July"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["July"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["July"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["July"] += int(s)
            elif(str[:1] == '8'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["August"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["August"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["August"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["August"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["August"] += int(s)
            elif(str[:1] == '9'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["September"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["September"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["September"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["September"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["September"] += int(s)
        else:
            if(str[:2] == '10'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["October"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["October"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["October"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["October"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["October"] += int(s)
            elif(str[:2] == '11'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["November"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["November"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["November"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["November"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["November"] += int(s)
            elif(str[:2] == '12'):
                s = li["amount"]
                if s == "sales amount ($)":
                    continue
                s = s[:-4] + s[(-4+1):]
                if(li["State"] == "California"):
                    statemonths["California"]["December"] += int(s)
                elif(li["State"] == "Texas"):
                    statemonths["Texas"]["December"] += int(s)
                elif(li["State"] == "Florida"):
                    statemonths["Florida"]["December"] += int(s)
                elif(li["State"] == "Nevada"):
                    statemonths["Nevada"]["December"] += int(s)
                elif(li["State"] == "Ohio"):
                    statemonths["Ohio"]["December"] += int(s)

print(statemonths)
# print(statemonths)
print("Dictionary ")
# for i in statemonths:
#     for j in i:
#         print(j)
# print(statemonths["Texas"])
# for i in statemonths["Texas"]:
#     print(i)
# myStateList = []
# for i in statemonths:
#     myStateList.append(i)

# print(myStateList)
# for i in myStateList:
#     myTuple = statemonths[i].values()
#     print(myTuple)
#     for i in my

# plt.plot(statemonths["Texas"].values(), statemonths["Florida"].values())
# plt.title('Amount of sale in year 2020')
# plt.xlabel('months')
# plt.ylabel('Amount of sale')
# plt.show()
