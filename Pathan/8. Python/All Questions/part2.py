def print_states(name, list_states):
    flag = True  # set flag to true
    for state in list_states:  # loop through all states
        if(len(state) > 0):  # state string is not null
            if(name == state[0]):  # if character is same
                print(state)  # print state
                flag = False
    if flag == True:  # if no state found
        print("No state found with this letter")  # print message


file1 = open("states.txt",  "r", encoding='utf8')  # open file to read
stateslist = file1.read().split("\n")  # split data from list by new line
name = input(
    "Enter the beginning letter of the state(s) you want to search for: ").upper()  # input starting character of state
print_states(name, stateslist)  # print states with characters
