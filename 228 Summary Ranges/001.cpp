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
        string s = itoa(st);
        if (st < en) 
            s += "->" + itoa(en);
        ans.push_back(s);
    }
    string itoa(int64_t x) {
        if (!x) return "0";
        string ans = "";
        bool isNeg = (x < 0);
        if (isNeg)  
            x = -x;
        while (x) {
            ans = char(x % 10 + '0') + ans;
            x /= 10;
        }
        if (isNeg) 
            ans = "-" + ans;
        return ans;
    }
};