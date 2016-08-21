class Solution {
public:
    void reverseWords(string &s) {
        ans = "";
        t = "";
        isFirst = true;
        for (char ch: s)
            if (ch != ' ')
                t.push_back(ch);
            else
                tryAppend();
        tryAppend();
        s = ans;
    }
private:
    string ans, t;
    bool isFirst;
    void tryAppend() {
        if (t.size()) {
            if (!isFirst)
                ans = " " + ans;
            ans = t + ans;
            isFirst = false;
        }
        t = "";
    }
};
