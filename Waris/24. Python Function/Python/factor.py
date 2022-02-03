

def factors(n):
    k = 1  # initializing k
    # yielder = []  # define yeilder
    while k*k < n:  # loop through numbers
        if n % k == 0:  # check if it is divisor
            yield k  # yield it
        k += 1  # incrementer
    k -= 1
    for i in range(k, n+1):
        if n % i == 0:
            yield i
    if k*k == n:
        yield k  # yielding k


num = int(input("Enter a number : "))
for n in factors(num):
    print(n)
