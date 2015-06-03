struct Comp {
    bool operator () (string &a, string &b) {
        string sa = a + b, sb = b + a;
        int l = sa.size();
        for (int i = 0; i < l; i++)
            if (sa[i] > sb[i])
                return true;
            else if (sa[i] < sb[i])
                return false;
        return false;
    }  
};

class Solution {
public:
    string largestNumber(vector<int> &num) {
        int n = num.size();
        vector<string> list;
        for (int i = 0; i < n; i++)
            list.push_back(itoa(num[i]));
        sort(list.begin(), list.end(), Comp());
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += list[i];
        int t = 0;
        while ((t < n-1) && (ans[t] == '0'))
            t++;
        return ans.substr(t);
    }
private:
    string itoa(int x) {
        string ans = "";
        do 
            ans = char('0' + x % 10) + ans;
        while (x /= 10);
        return ans;
    }
};