
# create list
southern_states = ["virginia", "tennessee", "arkansas", "louisiana", "north carolina", "south carolina", "mississippi",
                   "alabama", "georgia", "florida", "texas"]  # list of states


print("Report - Southern United States\n")
print("UNSORTED:\n")
i = 0  # counter for looping list


# print list unnsorted
# looping through list for i starts with zero to length of list
for i in range(len(southern_states)):
    print(f"{southern_states[i].title()}")  # print data on index of list


print("\nLast state of this unsorted list: ",
      southern_states[-1].title())  # print last item in list

print("\nSORTED:\n")
# sort a list
southern_states.sort()


# print list sorted
i = 0  # counter for looping list
# looping through list for i starts with zero to length of list
for i in range(len(southern_states)):
    print(f"{southern_states[i].title()}")  # print data on index of list


print("\nLast state of this unsorted list: ",
      southern_states[-1].title())  # print last item in list


# print length of list
print("\nNumber od Southern States : ", len(
    southern_states))  # prints length of list
print("\nSource: simple.wikipedia.org/wiki/Southern_United_States")
