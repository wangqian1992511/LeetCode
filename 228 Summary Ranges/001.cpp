class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (!n) return ans;
        st = en = nums[0];
        for (int i = 1; i < n; i++) 
            if (nums[i] == en + 1)
                en++;
            else {
                update();
                st = en = nums[i];
            }
        update();
        return ans;
    }
private:
    vector<string> ans;
    int64_t st, en;
    void update() {
        string s;
        itoa(s, st);
        if (st < en) {
            string t;
            itoa(t, en);
            s += "->" + t;
        }
        ans.push_back(s);
    }
    void itoa(string &s, int x) {
        stringstream sin;
        sin << x;
        sin >> s;
    }
};