class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if x < 0:
            return False
        t = x
        c = 0
        while t > 0:
            t /= 10
            c += 1
        for i  in range(c >> 1):
            t *= 10
            t += x % 10
            x /= 10
        if c & 1 == 1:
            x /= 10
        return x == t