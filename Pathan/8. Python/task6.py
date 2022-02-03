# Create a 3x3 array named a_matrix containing 11, 12, 13 in row 1, 14, 15,
# 16 in row 2 and 17,18, 19 in row 3
# Do NOT use the arange() or reshape() functions to create the array
# 2. Print a_matrix
# 3. Print the shape of the a_matrix
# 4. Get and print an array of diagonal entries from a_matrix
# 5. Calculate and print the minimum entry in a_matrix
# 6. Calculate and print the maximum entry in a_matrix
# 7. Calculate and print the sum of a_matrix
# 8. Use the arange() function to create a 1-D array named one_dim containing the int values 20 through 34
# 9. Print one_dim
# 10. Use the reshape function reshape 1-D into a 2-D array named two_dim with 5 rows and 3 columns
# 11. Print two_dim
# 12. Square every entry in two_dim using the ** operator and save the results in squared_two_dim
# 13. Print squared_two_dim


# 1. Create a 3x3 array named a_matrix containing 11, 12, 13 in row 1, 14, 15, 16 in row 2 and 17,18, 19 in row 3
import numpy as np
a_matrix = [[11, 12, 13], [14, 15, 16], [17, 18, 19]]

# 2. Print a_matrix
for a in a_matrix:
    print(a)


# 3. Print the shape of the a_matrix
if(len(a_matrix) == len(a_matrix[0])):
    print("\nMatrix Shape is Square")
else:
    print("\nMatrix Shape is Rectangle")


# 4. Get and print an array of diagonal entries from a_matrix
print("\nDiagonal Entries are:")
for i in range(0, len(a_matrix)):
    for j in range(0, len(a_matrix[i])):
        if(i == j):
            print(a_matrix[i][j])


# 5. Calculate and print the minimum entry in a_matrix

min = 20
for i in range(0, len(a_matrix)):
    for j in range(0, len(a_matrix[i])):
        if(a_matrix[i][j] < min):
            min = a_matrix[i][j]
print("\nMinimum Entry is:  " + str(min))


# 6. Calculate and print the maximum entry in a_matrix
max = 0
for i in range(0, len(a_matrix)):
    for j in range(0, len(a_matrix[i])):
        if(a_matrix[i][j] > max):
            max = a_matrix[i][j]
print("\nMaximum Entry is:  " + str(max))


# 7. Calculate and print the sum of a_matrix
sum = 0
for i in range(0, len(a_matrix)):
    for j in range(0, len(a_matrix[i])):
        sum += a_matrix[i][j]
print("\nSum of matrix is:  " + str(sum))


# 8. Use the arange() function to create a 1-D array named one_dim containing the int values 20 through 34

# create numpy array
print("\nOne dim array")
one_dim = np.arange(20, 35)

# 9. Print one_dim
print("\none_dim array")
print(one_dim)


# 10. Use the reshape function reshape 1-D into a 2-D array named two_dim with 5 rows and 3 columns
two_dim = np.reshape(one_dim, (5, 3))


# 11. Print two_dim
print("\nPrint two_dim")
for dim in two_dim:
    print(dim)


# 12. Square every entry in two_dim using the ** operator and save the results in squared_two_dim
for i in range(0, len(two_dim)):
    for j in range(0, len(two_dim[i])):
        two_dim[i][j] = two_dim[i][j] ** 2

# 13. Print squared_two_dim
print("\nPrint squared_two_dim")
for dim in two_dim:
    print(dim)
