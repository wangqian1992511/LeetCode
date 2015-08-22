class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (ns - nt == 1) 
            return isDel(t, s);
        else if (nt - ns == 1) 
            return isDel(s, t);
        else if (ns == nt) {
            int cnt = 0;
            for (int i = 0; i < ns; i++)
                cnt += (s[i] != t[i]);
            return cnt == 1;
        }
        else
            return false;
    }
private:
    bool isDel(string &t, string &s) {
        int cnt = 0,  nt = t.size(), ns = s.size();
        for (int i = 0; (i < nt) && (t[i] == s[i]); i++)
            cnt++;
        for (int i = nt; (i >= 0) && (t[i-1] == s[i]); i--)
            cnt++;
        return cnt == nt;
    }
};