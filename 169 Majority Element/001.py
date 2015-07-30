import random
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        d = {}
        while True:
            x = nums[random.randint(0, len(nums)-1)]
            cnt = 0
            for i in nums:
                if i == x:
                    cnt += 1
            if cnt > (len(nums) >> 1):
                return x