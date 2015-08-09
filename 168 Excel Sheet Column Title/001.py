class Solution:
    # @param {integer} n
    # @return {string}
    def convertToTitle(self, n):
        ans = ""
        while n > 0:
            ans = chr((n - 1) % 26 + ord('A')) + ans
            n = (n - 1) / 26
        return ans