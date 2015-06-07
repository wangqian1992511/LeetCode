class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(-1);
        int n = height.size();
        int ans = 0;
        stack<int> r, l;
        for (int i = 0; i < n; i++) {
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
        return ans;
    }
};
