class Solution
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target)
        d = {}
        for i in range(len(nums))
            if target - nums[i] in d
                return (d[target - nums[i]] + 1, i + 1)
            else
                d[nums[i]] = i