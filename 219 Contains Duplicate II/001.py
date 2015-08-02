class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        s = set()
        n = len(nums)
        for i in range(min(n, k)):
            if nums[i] not in s:
                s.add(nums[i])
            else:
                return True
        for i in range(k, n):
            if nums[i] in s:
                return True
            else:
                s.add(nums[i])
                s.remove(nums[i - k])
        return False