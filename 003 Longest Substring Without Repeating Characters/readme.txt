001.cpp (12ms):

Use two pointers to maintain the current substring. In fact, str[p ... q-1] is always valid. As long as we find than s[q] is used in the present substring, we should keep moving pointer p to avoid the previous usage of s[q].