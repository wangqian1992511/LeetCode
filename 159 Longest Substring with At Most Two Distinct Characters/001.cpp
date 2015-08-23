class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n <= 2) 
            return n;
        
        int p = 0, q = 1;
        char a = s[0], b;
        while ((q < n) && (s[q] == a)) 
            q++;
        if (q < n) 
            b = s[q];
        while ((q < n) && ((s[q] == a) || (s[q] == b))) 
            q++;
        if (s[q - 1] == a) 
            swap(a, b);
        
        int ans = q - p;
        while (q < n) {
            if (q < n) {
                a = b;
                b = s[q];
                p = q;
                while ((p > 0) && (s[p - 1] == a)) p--;
            }
            while ((q < n) && ((s[q] == a) || (s[q] == b))) 
                q++;
            if (s[q - 1] == a) 
                swap(a, b);            
            ans = max(ans, q - p);
        }
        return ans;
    }
};