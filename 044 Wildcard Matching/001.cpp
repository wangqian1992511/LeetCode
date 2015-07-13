struct pairT {
    int i, j;
};

struct hashFunc {
    size_t operator() (const pairT &a) const {
        return (a.i << 16) | a.j;
    }
};

struct compFunc {
    bool operator() (const pairT &a, const pairT &b) const {
        return (a.i == b.i) && (a.j == b.j);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        n = s.size();
        m = p.size();
        cnt = new int [m + 1];
        cnt[m] = 0;
        for (int j = m-1; j >= 0; j--)
            cnt[j] = cnt[j+1] + (p[j] != '*');
        return calcDP(0, 0);
    }
    
private:
    unordered_map<pairT, bool, hashFunc, compFunc> hash;
    int *cnt;
    int n, m;
    string s, p;
    
    bool calcDP(int i, int j) {
        if (n - i < cnt[j])
            return false;
        pairT pr = {i, j};
        if (hash.find(pr) == hash.end()) {
            if (j == m) 
                hash[pr] = (i == n);
            else if (i == n) 
                hash[pr] = (p[j] == '*') && calcDP(i, j + 1);
            else if ((s[i] == p[j]) || (p[j] == '?'))
                hash[pr] = calcDP(i + 1, j + 1);
            else if (p[j] != '*')
                hash[pr] = false;
            else 
                hash[pr] = calcDP(i + 1, j) || calcDP(i, j + 1);
        }
        return hash[pr];
    }
};