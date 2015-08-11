class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @param {integer} t
    # @return {boolean}
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if k <= 0 or t < 0 or len(nums) == 0:
            return False
        minV = min(nums)
        d = {}
        for i in range(len(nums)):
            if i > k:
                x = (nums[i - k - 1] - minV) // (t + 1)
                d[x].remove(nums[i - k - 1])
                if len(d[x]) == 0:
                    del d[x]
            x = (nums[i] - minV) // (t + 1)
            if x in d:
                return True
            else:
                d[x] = [nums[i]]
            if x + 1 in d:
                for ele in d[x + 1]:
                    if abs(ele - nums[i]) <= t:
                        return True
            if x - 1 in d:
                for ele in d[x - 1]:
                    if abs(ele - nums[i]) <= t:
                        return True      
        return False