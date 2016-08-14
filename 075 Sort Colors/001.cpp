class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        fill(cnt, cnt + 3, 0);
        for (auto it: nums)
            cnt[it]++;

        int p = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < cnt[i]; j++)
                nums[p++] = i;
    }
};
