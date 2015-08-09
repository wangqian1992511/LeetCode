class Solution:
    # @param {integer} n
    # @return {integer}
    def countDigitOne(self, n):
        ans = 0
        d = 1
        while d <= n:
            ans += n / 10 / d * d + min(d, max(0, 1 + n % (d * 10) - d))
            d *= 10
        return ans