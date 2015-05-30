class Solution {
public:
    int strStr(string text, string pattern) {
        int nT = text.size(), nP = pattern.size();
        if (!nP) return 0;
        
        bool *vis = new bool [256];
        fill(vis, vis + 256, false);
        for (int i = 0; i < nP; i++)
            vis[pattern[i]] = true;
        
        int *pi = new int [nP];
        pi[0] = 0;
        for (int i = 1, j = 0; i < nP; i++) {
            pi[i] = j;
            while ((j > 0) && (pattern[j] != pattern[i]))
                j = pi[j];
            if (pattern[j] == pattern[i]) 
                j++;  
        }
        
        for (int i = 0, j = 0; i < nT; i++) {
            while ((j > 0) && (pattern[j] != text[i]))
                if (nP - j + i >= nT)
                    return -1;
                else if (! vis[text[nP - j + i]]) {
                    j = 0;    
                    i += nP - j + 1;
                }
                else
                    j = pi[j];
            if (pattern[j] == text[i]) {
                j++;
                if (j == nP)
                    return i + 1 - nP;
            }
        }
        
        return -1;
    }
};
