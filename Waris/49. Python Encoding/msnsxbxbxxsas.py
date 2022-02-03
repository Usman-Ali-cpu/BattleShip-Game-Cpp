
def get_number(ch):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    return alphabet[ch-1]


def get_position(ch):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    i = 1
    for a in alphabet:
        if(a == ch):
            return i
        i += 1
    return 99


class LCL:

    @staticmethod
    def encode(message):
        message = message.upper()
        li = []
        for s in message:
            if(s == " "):
                li.append(0)
            else:
                pos = get_position(s)
                li.append(pos)
        out = ""
        for l in li:
            out += str(l) + " "
        return out

    @staticmethod
    def decode(message):
        arr = message.split(",")
        print(arr)
        strin = ""
        for a in arr:
            try:
                n = int(a)
            except:
                strin += "?"
                continue
            if n == 0:
                strin += " "
            elif n > 26 or n < 0:
                strin += "?"
            else:
                s = get_number(n)
                strin += s

        return strin


def main():
    print("Welcome to the LetterCode program\n")

    while True:
        print("Choice? (1=Encode, 2=Decode, 0=Quit): ")
        choice = int(input())
        if choice == 1:
            message = input("Enter your message to encode: ")
            output = LCL.encode(message)
            print("Your encoded message is: " + str(output))

        elif choice == 2:
            message = input(
                "Enter your numbers to decode (separate with commas):")
            output = LCL.decode(message)
            print("Your decoded message is:")
            print(output)

        elif choice == 0:
            print("\nThanks for using the LetterCode program!")
            return


main()
