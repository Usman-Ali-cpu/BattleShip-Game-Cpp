def odd_product(nums):  # funtion header
    for i in range(len(nums)):  # loop through all number in the array
        for j in range(len(nums)):  # inner loop through all numberss
            if i != j:  # if index of array is not same
                product = nums[i] * nums[j]  # find product of numbers at index
                if product & 1:  # check if product is odd
                    return True  # return true
    return False


dt1 = [2, 4, 6, 8]     # sequence of integer
dt2 = [1, 6, 4, 7, 8]  # second sequence of integer
dt3 = [1, 3, 5, 7, 9]  # third sequence of integer
print(dt1, odd_product(dt1))  # calling a function to get true or false
print(dt2, odd_product(dt2))  # calling a function to get true or false
print(dt3, odd_product(dt3))  # calling a function to get true or false
