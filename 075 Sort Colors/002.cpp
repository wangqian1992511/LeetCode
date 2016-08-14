class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        fill(p, p + 3, INT_MAX);
        for (int i = 0; i < n; i++) {
            p[nums[i]] = min(p[nums[i]], i);
            for (int x  = 0; x < 3; x++)
                if (nums[i] == x)
                    for (int y = x + 1; y < 3; y++)
                        if (isSwapped(nums, p[y], i))
                            break;
        }
    }
private:
    int p[3];
    bool isSwapped(vector<int>& nums, int bigP, int smallP) {
        if (bigP < smallP) {
            p[nums[smallP]] = min(bigP, p[nums[smallP]]);
            p[nums[bigP]]++;
            swap(nums[bigP], nums[smallP]);
            return true;
        }
        return false;
    }
};
