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
        cnt[j] = cnt[j + 1] + (p[j] != '*');
        return calcDP(0, 0);
    }
private:
    unordered_map<int, bool> hash;
    int *cnt;
    int n, m;
    string s, p;
    bool calcDP(int i, int j) {
        if (n - i < cnt[j])
        return false;
        int h = i * m + j;
        if (hash.find(h) == hash.end()) {
            if (j == m)
            hash[h] = (i == n);
            else if (i == n)
            hash[h] = (p[j] == '*') && calcDP(i, j + 1);
            else if ((s[i] == p[j]) || (p[j] == '?'))
            hash[h] = calcDP(i + 1, j + 1);
            else if (p[j] != '*')
            hash[h] = false;
            else
            hash[h] = calcDP(i + 1, j) || calcDP(i, j + 1);
        }
        return hash[h];
    }
};