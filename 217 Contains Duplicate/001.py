class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        s = set()
        for i in nums:
            if i not in s:
                s.add(i)
            else:
                return True
        return False