class Solution {
public:
    bool isAdditiveNumber(string num) {
        n = num.size();
        this->num = num;
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - i; j++)
                if (isValid(i, j, 0))
                    return true;
        return false;
    }
private:
    int n;
    string num;
    bool isValid(int la, int lb, int st) {
        string strA = num.substr(st, la);
        string strB = num.substr(st + la, lb);
        string strC = addStr(strA, strB);
        int pt = st + la + lb, lc = strC.size();
        for (int i = 0; i < lc; i++)
            if ((pt + i == n) || (strC[i] != num[pt + i]))
                return false;
        if (pt + lc == n)
            return true;
        return isValid(lb, lc, st + la);
    }
    string addStr(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int la = a.size();
        int lb = b.size();
        
        string ans = "";
        bool carry = false;
        int len = min(la, lb);
        for (int i = 0; i < len; i++)
            if (a[i] + b[i] - '0' + carry > '9') {
                ans.push_back(a[i] + b[i] - '0' + carry - 10);
                carry = true;
            }
            else {
                ans.push_back(a[i] + b[i] - '0' + carry);
                carry = false;
            }
        for (int i = len; i < la; i++)
            if (a[i] + carry > '9') {
                ans.push_back(a[i] + carry - 10);
                carry = true;
            }
            else {
                ans.push_back(a[i] + carry);
                carry = false;
            }
        for (int i = len; i < lb; i++)
            if (b[i] + carry > '9') {
                ans.push_back(b[i] + carry - 10);
                carry = true;
            }
            else {
                ans.push_back(b[i] + carry);
                carry = false;
            }
        if (carry)
            ans.push_back('1');
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};