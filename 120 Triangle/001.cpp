class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (!n) return 0;
        int *ans[2];
        bool ansP = false;
        ans[0] = new int [n];
        ans[1] = new int [n];

        ans[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            ansP = !ansP;
            ans[ansP][0] = ans[!ansP][0] + triangle[i][0];
            ans[ansP][i] = ans[!ansP][i-1] + triangle[i][i];
            for (int j = 1; j < i; j++) {
                ans[ansP][j] = triangle[i][j] + (ans[!ansP][j] < ans[!ansP][j-1] ? ans[!ansP][j] : ans[!ansP][j-1]);
            }
        }
        
        int a = ans[ansP][0];
        for (int i = 1; i < n; i++)
            if (a > ans[ansP][i])
                a = ans[ansP][i];
        return a;
    }
};
