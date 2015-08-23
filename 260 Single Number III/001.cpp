class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for (auto it = nums.begin(); it != nums.end(); it++)
            ab ^= *it;
        int a = 0, t = ab & -ab;
        for (auto it = nums.begin(); it != nums.end(); it++)
            if (*it & t)
                a ^= *it;
        int b = ab ^ a;
        return {a, b};
    }
};