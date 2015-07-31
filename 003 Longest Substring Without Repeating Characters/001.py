class Solution:
    # @param {string} str
    # @return {integer}
    def lengthOfLongestSubstring(self, str):
        s = set()
        ans = p = q = 0
        while q < len(str):
            if str[q] not in s:
                s.add(str[q])
                q += 1
            else:
                while str[q] in s:
                    s.remove(str[p])
                    p += 1
            ans = max(ans, q - p)
        return ans