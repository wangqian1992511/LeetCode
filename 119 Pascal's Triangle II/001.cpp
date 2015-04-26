class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans[2];
        bool isAns = false;
        ans[0].push_back(1);
        
        for (int i = 1; i <= rowIndex; i++) {
            isAns = !isAns;
            ans[isAns].clear();
            ans[isAns].push_back(1);
            for (int j = 1; j < i; j++)
                ans[isAns].push_back(ans[!isAns][j-1] + ans[!isAns][j]);
            ans[isAns].push_back(1);
        }
        return ans[isAns];
    }
};