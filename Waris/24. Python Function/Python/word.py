def frequencyofwords(word, wordlist):
    count = 0
    for s in wordList:
        print(s + " " + word)
        if s == word:
            count += 1
    return count  # return count of word in that list


# input string and store as list by spliting
wordList = input("Enter a String : ")
listofWord = wordList.split(' ')
wordstemp = []  # declaring array
for word in listofWord:  # traversing all words of list
    wordstemp.append(word)  # append word in temp list
    # find frequency of word in list
    count = frequencyofwords(word, listofWord)
    # if wordstemp.count(word) == 1:  # to check it is already printed
    print(word + " = ", count)
