import random
class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def majorityElement(self, nums):
        if nums == []:
            return ()
        a = []
        for t in range(10):
            x = nums[random.randint(0, len(nums) - 1)]
            if x in a:
                continue
            cnt = 0
            for i in nums:
                if i == x:
                    cnt += 1
            if cnt > len(nums) / 3 and x not in a:
                a += [x]
        return a