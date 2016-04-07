class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        fill(cnt, cnt + 256, 0);
        if (!k) return 0;
        
        n = s.size();
        k = min(n, k);
        
        p = q = 0;
        ans = k;
        while (q < n) {
            while (canGoOn(s, k)) {
                addIt(s);
                ans = max(ans, q - p);
            }
            removeIt(s);
        }
        
        return ans;
    }
private:
    int cnt[256];
    unordered_set<char> appear;
    int p, q, n, ans;
    
    void removeIt(string &s) {
        cnt[s[p]]--;
        if (!cnt[s[p]]) appear.erase(s[p]);
        p++;
    }
    
    void addIt(string &s) {
        appear.insert(s[q]);
        cnt[s[q]]++;
        q++;
    }
    
    bool canGoOn(string &s, int k) {
        if (q >= n) return false;
        if (appear.find(s[q]) != appear.end()) return true;
        if (appear.size() < k) return true;
        return false;
    }
};