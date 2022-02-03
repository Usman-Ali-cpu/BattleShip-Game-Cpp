def foo(s, t):
    i = 0
    while i < len(t):
        j = 0
        while j < len(s) and s[j] == t[(j+i) % len(t)-1]:
            j += 1
        if(j == len(s)):
            return i
        i += 1
    return -1


print(foo("ab", "caabc"))
print(foo("abc", "caabc"))
print(foo("ac", "caabc"))
print(foo("ac", "caabca"))
