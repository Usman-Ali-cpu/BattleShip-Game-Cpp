def print_states(name, list_states):
    for state in list_states:
        if(len(state) > 0):
            if(name == state[0]):
                print(state)


file1 = open("states.txt",  "r", encoding='utf8')
stateslist = file1.read().split("\n")
name = input(
    "Enter the beginning letter of the state(s) you want to search for: ").upper()
print_states(name, stateslist)
