class Solution:
    # @param {integer} n
    # @return {integer}
    def trailingZeroes(self, n):
        ans = 0
        p = 5
        while p <= n:
            ans += n / p
            p *= 5
        return ans