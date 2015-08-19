class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> half = build(n >> 1, true);
        int m = half.size();
        vector<string> ans;
        if (n & 1) 
            for (int i = 0; i < m; i++) {
                string t = half[i];
                ans.push_back(t + '0' + strobo(t));
                ans.push_back(t + '1' + strobo(t));
                ans.push_back(t + '8' + strobo(t));
            }
        else 
            for (int i = 0; i < m; i++) {
                string t = half[i];
                ans.push_back(t + strobo(t));
            }
        return ans;
    }
private:
    string strobo(string t) {
        string ans = "";
        int n = t.size();
        for (int i = 0; i < n; i++)
            switch (t[i]) {
                case '0':
                case '1':
                case '8': ans = t[i] + ans;
                        break;
                case '6': ans = '9' + ans;
                        break;
                case '9': ans = '6' + ans;
            }
        return ans;
    }
    vector<string> build(int l, bool flag) {
        vector<string> ans;
        if (!l) {
            ans.push_back("");
            return ans;
        }
        vector<string> half = build(l - 1, false);
        int n = half.size();
        for (int i = 0; i < n; i++) {
            string t = half[i];
            if (!flag) ans.push_back('0' + t);
            ans.push_back('1' + t);
            ans.push_back('6' + t);
            ans.push_back('8' + t);
            ans.push_back('9' + t);
        }
        return ans;
    }
};