class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while ((nums[i] == val) && (i < n)) 
                nums[i] = nums[n---1];
        return n;
    }
};