class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int l = n - m + 1;
        int ans = 0xffffffff;
        for (int i = 0; i < 32; i++)
            ans &= (0xffffffff - (((l > (1 << i)) | !((1 << i) & m & n)) << i));
        return ans;
    }
};