class Solution {
public:
    void reverseWords(string &s) {
        istringstream strin (s);
        string ans = "", t;
        bool isFirst = true;
        while (strin >> t) {
            if (!isFirst)
                ans = " " + ans;
            isFirst = false;
            ans = t + ans;
        }
        s = ans;
    }
};
