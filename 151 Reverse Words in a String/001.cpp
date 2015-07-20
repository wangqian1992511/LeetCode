class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        string tmp = "", ans = "";
        bool flag = false;
        for (int i = 0; i < n; i ++)
            if (s[i] != ' ')
                tmp += s[i];
            else if (tmp.size()) {
                if (!flag) {
                    flag = true;
                    ans = tmp;
                }
                else
                    ans = tmp + ' ' + ans;
                tmp = "";
            }
        if (tmp.size()) {
            if (!flag) 
                ans = tmp;
            else
                ans = tmp + ' ' + ans;
        }
        s = ans;
    }
};