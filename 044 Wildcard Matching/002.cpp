class Solution {
public:
    bool isMatch(string s, string p) {
        if (shrinkString(s, p)) {
            dividePattern(p);
            int t = sub.size();
            for (int i = 0; i < t; i++) 
                if (!kmp(i, s))
                    return false;
            return true;
        }
		return false;
    }
    
private:
    bool haveStStar, haveEnStar;
    int n, m, k;
    vector<string> sub;
    
    bool shrinkString(string &s, string &p) {
        n = s.size();
        m = p.size();
        int i = 0;
        while ((i < n) && (i < m) && (p[i] != '*')) {
            if (isMatchChar(s[i], p[i])) 
                i++;
            else
                return false;
        }
        s = s.substr(i);
        p = p.substr(i);
        
        n = s.size();
        m = p.size();
        int r = n-1, t = m-1;
        while ((r >= 0) && (t >= 0) && (p[t] != '*')) {
            if (isMatchChar(s[r], p[t])) {
                t--;
                r--;
            }
            else
                return false;
        }
        s = s.substr(0, r+1);
        p = p.substr(0, t+1);
        
        n = s.size();
        m = p.size(); 
        k = 0;
        if (p == "") 
            return s == "";
        return true;
    }
    
    void dividePattern(string &p) {
        int t = 0;
        while (t < m) {
            while ((t < m) && (p[t] == '*')) 
                t++;
            int l = 0;
            while ((t + l < m) && (p[t + l] != '*')) 
                l++;
            if (l) sub.push_back(p.substr(t, l));
            t += l;
        }
    }
    
    bool kmp(int x, string &s) {
        string p = sub[x];
        vector<int> pi;
        calcPrefix(p, pi);
        int t = 0, l = p.size();
        while (k < n) {
            while ((t > 0) && !isMatchChar(p[t], s[k]))
                t = pi[t];
            if (isMatchChar(p[t], s[k])) 
                t++;
            k++;
            if (t == l) 
                return true;
        }
        return false;
    }
    
    void calcPrefix(string &p, vector<int> &pi) {
        pi.push_back(0);
        int t = 0, l = p.size();
        for (int i = 1; i < l; i++) {
			pi.push_back(t);
            while ((t > 0) && !isMatchChar(p[t], p[i]))
                t = pi[t];
            if (isMatchChar(p[t], p[i]))
                t++;            
        }
    }
    
    bool isMatchChar(char a, char b) {
        return (a == b) || (a == '?') || (b == '?');
    }
};