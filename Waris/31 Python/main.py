import re
import math

#!/usr/bin/env python3
# # -*- coding: utf-8 -*-
""" Eliza like program """
__author__ = "my name"

print("Enter your name:")
n = input().strip()
n = n.lower()
narr = n.split(" ")
name = ""
if narr[0] == "i":
    name = narr[len(narr)-1]
if narr[len(narr)-1] == "name":
    name = narr[0]
if narr[0] == "my":
    name = narr[len(narr)-1]


terminate = "bye"
print("Hi!", name, "sir, How can i help you?")

dictionary = {
    "comp": ["good", "bad", "ok", "nice"],
    "relation":  ["mother",  "mom", "dad", "father", "brother", "sister", "friend"]
}
count = 1
while(1):
    x = input().strip()
    x1 = x.lower()
    if(terminate in x1):
        break
    elif(re.search("sad.*", x1)):
        print("Why are you feeling sad?")
        count = 0
    elif(re.search("joy.*", x1)):
        print("I feel like you are enjoying your life very well.")
        count = 0
    elif(re.search("happy.*", x1)):
        print("I feel like you are happy in your life very well.")
        count = 0
    elif(re.search(".*ed", x1)):
        words = x1.split()
        for word in words:
            if word.endswith("ed"):
                print("When did it", word[:-2], "?")
                count = 0
                break
    else:
        for i in dictionary["comp"]:
            if i in x1:
                print("It is", i, ".")
            count = 0
    if(count == 0):
        for i in dictionary["relation"]:
            if i in x1:
                print("Oh! how are you", i, "?")
