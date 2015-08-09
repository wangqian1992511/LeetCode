class Solution:
    # @param {string} s
    # @return {integer}
    def titleToNumber(self, s):
        n = len(s)
        ans = 0
        for ch in s:
            ans *= 26
            ans += ord(ch) - ord('A') + 1
        return ans