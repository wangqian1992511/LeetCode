class Solution {
public:
    bool isPalindrome(string s) {
        int p = 0, q = s.size() - 1;
        while (p < q) {
            while (!isAlphaNum(s[p]) && (p < q)) 
                p++;
            while (!isAlphaNum(s[q]) && (p < q)) 
                q--;
            if (!isEq(s[p], s[q])) 
                return false;
            p++;
            q--;
        }
        return true;
    }
private:
    bool isAlphaNum(char ch) {
        if (('a' <= ch) && (ch <= 'z')) 
            return true;
        if (('A' <= ch) && (ch <= 'Z')) 
            return true;
        if (('0' <= ch) && (ch <= '9'))
            return true;
        return false;
    }
    bool isEq(char a, char b) {
        if (a == b)
            return true;
        if (b - a == 'A' - 'a')
            return true;
        if (a - b == 'A' - 'a')
            return true;
        return false;
    }
};