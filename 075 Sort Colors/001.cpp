class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p[3] = {0};
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (i != p[x]) {
                swap(nums[i], nums[p[x]]);
                update(p, x);
                x = nums[i];
            }
            update(p, x);
        }
    }
private:
    void update(int p[], int x) {
        p[x]++;
        if (p[1] < p[0]) p[1] = p[0];
        if (p[2] < p[1]) p[2] = p[1];
        
    }
};
