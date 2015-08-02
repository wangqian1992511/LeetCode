class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        ans = []
        n = len(nums)
        if n == 0:
            return ans
        en = st = nums[0]
        for i in range(1, n):
            if nums[i] == en + 1:
                en += 1
            else:
                ans.append(self.make(st, en))
                st = en = nums[i]
        ans.append(self.make(st, en))
        return ans
    def make(self, st, en):
        ans = str(st)
        if st < en:
            ans += "->" + str(en)
        return ans