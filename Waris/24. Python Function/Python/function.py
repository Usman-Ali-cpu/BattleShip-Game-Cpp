def is_odd_product(sIntegers):  # funtion header
    for i in range(len(sIntegers)):  # loop through all number in the array
        for j in range(len(sIntegers)):  # inner loop through all numberss
            if i != j:  # if index of array is not same
                # find product of numbers at index
                product = sIntegers[i] * sIntegers[j]
                if product & 1:  # check if product is odd
                    return True  # return true
    return False


integers1 = [2, 4, 6, 8, 10, 12]     # sequence of integer
integers2 = [1, 6, 4, 7, 8, 9, 11, 12]  # second sequence of integer
# calling a function to get true or false
print("First Sequence : " + str(integers1))
if is_odd_product(integers1):
    print("It has pair of numbers whose product is odd")
else:
    print("It does not have any pair whose product is odd")
# calling a function to get true or false
print("\nSecond Sequence : " + str(integers2))
if is_odd_product(integers2):
    print("It has pair of numbers whose product is odd")
else:
    print("It does not have any pair whose product is odd")
