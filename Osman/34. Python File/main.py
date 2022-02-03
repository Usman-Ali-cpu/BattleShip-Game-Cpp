from datetime import datetime

# datetime object containing current date and time
now = datetime.now()
# dd/mm/YY H:M:S
dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
print("\nDate and Time =", dt_string, "\n")


packfile = open("confPack.txt", "r")  # open file to read
packlines = []  # declare list to store pack names
for li in packfile:  # loop thorugh lines reas by files
    packlines.append(li)  # add to list of packs


basic = packlines[0]  # first pack is basic
bonus = packlines[1]  # second pack is bonus


file = open("employees.txt", "r")  # open employee file to read

for line in file:  # loop through lines read from file, one by one
    # separate out each word in a line by comma, and store as list
    elements = line.split(",")
    length = len(elements)  # get length of list, how many words are there
    # check if length is 3 and last word is Y
    if(length == 3 and elements[length-1][0] == 'Y'):
        print("Attendee: [", elements[0] + " " + elements[1], "] Pack/s [", basic[:-1], "]")
    # check if length is 4 and second last and last word is Y
    elif(length == 4 and elements[length-1][0] == 'Y' and elements[length-2] == "Y"):
        print("Attendee: [", elements[0] + " " + elements[1], "] Pack/s [", basic[:-1], ", ", bonus, "]")
    # check if length is 4 and second last is blank and last word is Y
    elif(length == 4 and elements[length-1][0] == 'Y' and elements[length-2] == ""):
        print("Attendee: [", elements[0] + " " + elements[1], "] Pack/s [", bonus, "]")
    else:
        print("Attendee: [", elements[0] + " " + elements[1][:-1], "] Pack/s [", "not attending]")
