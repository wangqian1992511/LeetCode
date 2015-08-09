class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        ans = []
        d = 1
        for x in nums:
            ans.append(d)
            d *= x
        d = 1
        for i in range(len(nums)-1, -1, -1):
            ans[i] *= d
            d *= nums[i]
        return ans