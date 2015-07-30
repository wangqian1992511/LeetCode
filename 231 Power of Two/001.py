class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        return n == (n & -n) if n > 0 else False