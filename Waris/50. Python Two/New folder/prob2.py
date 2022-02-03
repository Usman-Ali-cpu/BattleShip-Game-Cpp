
from os import write


def isbn_checker(isbn_num):
    count = 0
    summ = 0
    for ch in isbn_num:
        if(ch.isdigit()):
            count += 1
            if(count % 2 == 1):
                num = int(ch)
                n = num * 1
                summ += n
            if(count % 2 == 0):
                num = int(ch)
                n = num * 3
                summ += n
    if(summ % 10 == 0):
        return "VALID"
    else:
        print(summ % 10)
        line = str(summ % 10)
        return line


def main():
    file = open("Prob02.in.txt", 'r')
    wfile = open("prob02.out.txt", 'w')
    for f in file:
        line = isbn_checker(f)
        wfile.writelines(line + "\n")


main()
