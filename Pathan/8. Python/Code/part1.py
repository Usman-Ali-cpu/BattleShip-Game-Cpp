file1 = open("state_list.txt",  "r", encoding='utf8')
states = file1.read()
states = states[1:len(states)-1]
list_states = states.split("\n")
f = open("states.txt", "w")
file1.close()

for s in list_states:
    states_in_line = s.split(",")
    for li in states_in_line:
        if(len(li) == 0 or li[0] == ' '):
            continue
        li = li[1:len(li)-1]
        if(li[len(li)-1] == '\"'):
            li = li[0:len(li)-1]
        print(li)
        f.write(li+"\n")
print("File has been written successfully")
f.close()
