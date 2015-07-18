class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n || !k) 
            return ans;
        m = k;
        for (int i = 0; i < m-1; i++) 
            pushIt(nums[i], i);
        for (int i = m-1; i < n; i++) {
            pushIt(nums[i], i);
            ans.push_back(q.front());
        }
        return ans;
    }
private:
    vector<int> ans;
    deque<int> q, t;  
    int m;
    void pushIt(int x, int i) {
        if (t.front() + m == i) {
            q.pop_front();
            t.pop_front();
        }
        while (!q.empty() && (q.back() <= x)) {
            q.pop_back();
            t.pop_back();
        }
        q.push_back(x);
        t.push_back(i);
    }
};