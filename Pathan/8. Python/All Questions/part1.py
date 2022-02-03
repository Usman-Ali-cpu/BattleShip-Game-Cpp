file1 = open("state_list.txt",  "r", encoding='utf8')  # open file to read
states = file1.read()  # read all data from file
states = states[1:len(states)-1]  # get all lines execpt first line
list_states = states.split("\n")  # split string by new line and make a list
f = open("states.txt", "w")  # open file to write
file1.close()  # close reading file

for s in list_states:  # loop through list of states
    # split each line by , and store in array of states in line
    states_in_line = s.split(",")
    for li in states_in_line:  # loop through that list
        if(len(li) == 0 or li[0] == ' '):
            continue
        li = li[1:len(li)-1]  # get a state
        if(li[len(li)-1] == '\"'):
            li = li[0:len(li)-1]
        print(li)
        f.write(li+"\n")  # write state in the file
print("File has been written successfully")
f.close()
