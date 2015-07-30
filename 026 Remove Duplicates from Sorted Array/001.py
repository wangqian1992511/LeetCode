class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        if len(nums) <= 1:
            return len(nums)
        tot = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[tot] = nums[i]
                tot += 1
        return tot