class Solution {
public:
    int maxArea(vector<int>& height) {
        int p = 0, q = height.size()-1;
        int ans = 0;
        while (p < q) {
            ans = max(ans, min(height[p], height[q]) * (q - p));
            if (height[p] < height[q])
                p++;
            else
                q--;
        }
        return ans;
    }
};