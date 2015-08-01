class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - 97] += 1
        for ch in t:
            cnt[ord(ch) - 97] -= 1
        return cnt == [0] * 26