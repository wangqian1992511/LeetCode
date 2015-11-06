class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        maxAnsLen = 0;
        strLen = s.size();
        cnt = 0;
        str = s;
        tmp = "";
        
        numAntiP = new int [strLen + 1];
        jump = new int [strLen + 1];
        numAntiP[strLen] = 0;
        jump[strLen] = strLen;
        str.push_back('@');
        for (int i = strLen - 1; i >= 0; i--) {
            numAntiP[i] = numAntiP[i + 1] + (str[i] == ')');
            if (str[i] == ')')
                jump[i] = (str[i + 1] == ')') ? jump[i + 1] : (i + 1);
            if (str[i] == '(')
                jump[i] = (str[i + 1] == '(') ? jump[i + 1] : (i + 1);
        }
        
        dfs(0);
        return ans;
    }
private:
    int cnt, *numAntiP, *jump, strLen, maxAnsLen;
    vector<string> ans;
    string str, tmp;
    void dfs(int i) {
        if (strLen - i + tmp.size() < maxAnsLen)
            return;
        else if (i == strLen) {
            maxAnsLen = tmp.size();
            ans.push_back(tmp);
        }
        else if (str[i] == ')') {
            if (cnt > 0) {
                cnt--;
                tmp.push_back(str[i]);
                dfs(i + 1);
                tmp.pop_back();
                cnt++;
            }
            if (numAntiP[i + 1] >= cnt)
                dfs(jump[i]);
        }
        else if (str[i] == '(') {
            if (numAntiP[i + 1] > cnt) {
                cnt++;
                tmp.push_back(str[i]);
                dfs(i + 1);
                tmp.pop_back();
                cnt--;
            }
            dfs(jump[i]);
        }
        else {
            tmp.push_back(str[i]);
            dfs(i + 1);
            tmp.pop_back();
        }
    }
};