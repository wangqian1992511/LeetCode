class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k):
        return self.findIt(nums, 0, len(nums) - 1, k - 1)    
    def findIt(self, nums, st, en, k):
        if st == en:
            return nums[st]
        l = st
        r = en
        key = nums[(l + r) >> 1]
        while l <= r:
            while nums[l] > key:
                l += 1
            while nums[r] < key:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        if k <= r:
            return self.findIt(nums, st, r, k)
        elif k >= l:
            return self.findIt(nums, l, en, k)
        else:
            return nums[r + 1] 