class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", 1);
        return ans;
    }
private:
    vector<string> ans;
    void dfs(string rmn, string now, int dep) {
        int n = rmn.size();
        if (!n) 
            return;
        else if (dep == 4) {
            if (isValid(rmn))
                ans.push_back(now+rmn);
        }
        else {
            for (int i = 1; i <= min(3,n); i++) {
                string str = rmn.substr(0,i);
                if (isValid(str))
                    dfs(rmn.substr(i), now+str+'.', dep+1);
            }
        }
    }
    bool isValid(string str) {
        int n = str.size();
        if (n < 1) return false;
        if (n == 1) return true;
        if (str[0] == '0') return false;
        if (n == 2) return true;
        if (n > 3) return false;
        if (str[0] > '2') return false;
        if (str[0] < '2') return true;
        if (str[1] > '5') return false;
        if (str[1] < '5') return true;
        if (str[2] > '5') return false;
        return true;
    }
};