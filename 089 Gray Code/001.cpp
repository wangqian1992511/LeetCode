class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int m = 1 << n;
        for (int i = 0; i < m; i++) {
            int t = i & (1 << (n - 1));
            bool thisOne, nextOne = i & 1;
            for (int j = 0; j < n - 1; j++) {
                thisOne = nextOne;
                nextOne = (i & (1 << (j + 1)));
                if (thisOne ^ nextOne)
                    t = t | (1 << j);
            }
            ans.push_back(t);
        }
        return ans;
    }
};