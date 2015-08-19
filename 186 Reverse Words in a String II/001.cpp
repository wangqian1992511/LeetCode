class Solution {
public:
    void reverseWords(string &s) {
        int p = 0, q = 0, n = s.size();
        while (q < n) {
            while ((q < n) && (s[q] != ' ')) q++;
            reverse(s.begin() + p, s.begin() + q);
            p = ++q;
        }
        reverse(s.begin(), s.end());
    }
};