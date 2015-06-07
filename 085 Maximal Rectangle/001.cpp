class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        if (!m) return 0;
        int ans = 0;
        vector<int> height (m, 0);
        height.push_back(-1);
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++)
                if (matrix[k][j] == '0')
                    height[j] = 0;
                else
                    height[j]++;
            stack<int> r, l;
            for (int i = 0; i <= m; i++) {
                if (r.empty() || (height[i] > height[r.top()])) {
                    r.push(i);
                    l.push(i);
                }
                else if (height[i] == height[r.top()]) {
                    r.pop();
                    r.push(i);
                }
                else if (height[i] < height[r.top()]) {
                    while ((!r.empty()) && (height[i] < height[r.top()])) {
                        int len = i - l.top();
                        ans = max(ans, height[r.top()] * len);
                        r.pop();
                        l.pop();
                    }
                    if (r.empty())
                        l.push(0);
                    else if (height[i] == height[r.top()]) 
                        r.pop();
                    else
                        l.push(r.top() + 1);
                    r.push(i);
                }
            }
        }
        return ans;
    }
};
