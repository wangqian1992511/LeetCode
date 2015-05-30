001.cpp (160ms):

O(n^2) DP solution.

dp[i][i+k] = dp[i+1][i+k-1] && (s[i] == s[i+k])
dp[i][i] = true
dp[i+1][i] = true

The last initial condition is only for convenience of calculation.

002.cpp (8ms):

This solution is my first implementation of Manacher's Algorithm. 

First, convert the original string to a new string by inserting "#" between every characters. To avoid the boundary case, put "!" at the beginning and put "@" at the end of the string. 

e.g. "dabbacd" -> "!#d#a#b#b#a#c#d#@"

Then, check every character one by one. The variable "p[i]" is used to record the distance between the nearest unmatched characters to the center of a palindromic substring. 

e.g. "!#d#a#b#b#a#c#d#@" -> p[7] = 5

If we call the characters in the visited palindromic substring "covered characters", then "maxD" is used to indicate the index of the furtherest uncovered character. Thus, "id" is used to indicate the index of the center of the palindromic substring next to that corresponding uncovred character.

e.g. "!#d#a#b#b#a#c#d#@" -> when i = 7, update id = 7, maxD = 7 + 5 = 12

Thanks the palindrome substring centered by the id-th element, we find that if the i-th element is on the left of the maxD-th element, then we can find its symmetric element whose index is "2 * id - i" in this substring. For this i-th element, we don't need to calculate the palindromic substring centered by it naively. Instead, we first make use the information "p[2 * id - i]". If this value is not smaller than "maxD - i", then we should perform a naive check from the maxD-th element with its symmetric element to i-th element.

This algorithm has a time complexity of O(n). Notice the inner loop. Every increment to any "p[i]" is later equivalent to an increment to "maxD". That is to say, the increment in the while-loop can only be performed for at most "m" times. Thus this do not influence the time complexity of the whole algorithm.

I always wonder why palindrome should be studied. Is it only a practice for beginner of programming? I searched the Internet, and it said that palindrome is meaningful in biology (sth about DNA). Unfortunately, I never had an experience of learning biology, even during my high school life. Haha~~~


