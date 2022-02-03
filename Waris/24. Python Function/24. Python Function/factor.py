def print_factors(x):  # function header
    print("The factors of", x, "are:")  # prints statement
    for i in range(1, x + 1):  # looping through each number from one to +1 of given number
        if x % i == 0:  # number is factor, reminder of given number with looping number is 0
            print(i)  # print that number


num = 320  # a number

print_factors(num)  # calling function to get factors in increasing order
