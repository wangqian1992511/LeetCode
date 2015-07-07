001.cpp (16ms):

Since there are only four kinds of characters to be discussed and the length of the substrings we care about is always 10, there are at most 0xfffff differemt substrings. Use two sets to record whether a substring has appearred and been pushed in to the answer vector.