class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        d = {}
        for i in range(len(nums)):
            if target - nums[i] in d:
                return (d[target - nums[i]], i)
            else:
                d[nums[i]] = i
