class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int ans = 0, tmp = 0;
        bool isAdd = true, isRev = false;
        stack<bool> rev;
        for (int i = 0; i < n; i++) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                tmp = tmp * 10 + int(s[i] - '0');
            else if (s[i] == '+') {
                calc(ans, tmp, isAdd, isRev);
                isAdd = true;
            }
            else if (s[i] == '-') {
                calc(ans, tmp, isAdd, isRev);
                isAdd = false;
            }
            else if (s[i] == '(') {
                rev.push(isRev);
                isRev = !(isAdd ^ isRev);
                isAdd = true;
            }
            else if (s[i] == ')') {
                calc(ans, tmp, isAdd, isRev);
                isRev = rev.top();
                rev.pop();
            }
            else if (s[i] == ' ')
                calc(ans, tmp, isAdd, isRev);
        }
        calc(ans, tmp, isAdd, isRev);
        return ans;
    }
private:
    void calc(int &ans, int &tmp, bool isAdd, bool isRev) {
        if (isAdd ^ isRev)
            ans += tmp;
        else
            ans -= tmp;
        tmp = 0;
    }
};