def frequencyofwords(words):  # function header
    wordfreq = []  # list of frequency of words
    wordslist = words.split(' ')  # split string by space and store in list
    for word in wordslist:  # looping thorugh list of words
        # store frequency of words in wordfreq by getting count of that word
        wordfreq.append(wordslist.count(word))
    # make key value pair by ziping and return dictionary
    return dict(list(zip(wordslist, wordfreq)))


wordList = "It is list of words separated by space. It is required to find how many times each word appears in list"
wordCounts = frequencyofwords(wordList)  # calling function
for word in wordCounts:  # looping through dictionary
    # print key and value , word and count
    print(word + " = " + str(wordCounts[word]))
