class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        pos = x >= 0
        if not pos:
            x = -x
        t = 0
        while x > 0:
            t *= 10
            t += x % 10
            x /= 10
        if t < -2 ** 31 or t >= 2 ** 31:
            return 0   
        return t if pos else -t