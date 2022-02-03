
# create list of weekdays
days_of_week = ["Monday", "Tuesday", "Wednesday",
                "Thursday", "Friday", "Saturday", "Sunday"]  # list of days of week


# create a list of daily sales
daily_sales = [1000, 2000, 3000, 4000, 5000, 6000, 7000]  # list of daily sales


print("\nACME Stores Incorporated Sales Report: \n")
print("Current Sales:\n")


# print orignal lists
i = 0  # counter for loop
# looping through list for i starts with zero to length of list
for i in range(len(days_of_week)):
    # prints data on index i of both lists, day:sales
    print(f"{days_of_week[i].title()}: \t ${daily_sales[i]:,.2f}")


# prints daysweek and dailysale after increase of 5%
print("\nProjected 5% Increase:\n")
i = 0
# looping through list for i starts with zero to length of list
for i in range(len(days_of_week)):
    daily_sales[i] = daily_sales[i] * 1.05  # add 5% to daily sales
    # prints data on index i of both lists, day:sales
    print(f"{days_of_week[i].title()}: \t ${daily_sales[i]:,.2f}")
