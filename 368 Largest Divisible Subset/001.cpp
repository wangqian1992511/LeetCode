class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), idx = 0, ansLen = 1;
        if (!n) return vector<int> ();
        int* len = new int [n];
        int* pre = new int [n];

        for (int i = 0; i < n; i++) {
            len[i] = 1;
            pre[i] = -1;
            for (int j = 0; j < i; j++)
                if (!(nums[i] % nums[j]) && (len[j] + 1 > len[i])) {
                    len[i] = len[j] + 1;
                    if (len[i] > ansLen) {
                        ansLen = len[i];
                        idx = i;
                    }
                    pre[i] = j;
                }
        }

        vector<int> ansArr;
        while (idx > -1) {
            ansArr.push_back(nums[idx]);
            idx = pre[idx];
        }
        return ansArr;
    }
};
