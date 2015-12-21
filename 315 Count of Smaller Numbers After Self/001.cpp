class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> data (nums);
        sort(data.begin(), data.end());
        
        n = data.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
            hash[data[i]] = i + 1;
        
        c = new int [n + 1];
        fill(c, c + n + 1, 0);
        vector<int> ans (n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int t = hash[nums[i]];
            add(t);
            ans[i] = sum(t - 1);
        }
        return ans;
    }
private:
    int *c, n;
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x) {
        while (x <= n) {
            c[x]++;
            x += lowbit(x);
        }
    }
    int sum(int x) {
        int ans = 0;
        while (x) {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
    
};