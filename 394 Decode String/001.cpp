class Solution {
public:
    string decodeString(string s) {
        stack<int> rep;
        stack<string> str;
        rep.push(0);
        str.push("");

        int tot = 0;
        for (auto ch: s) {
            if (('0' <= ch) && (ch <= '9'))
                tot = tot * 10 + int(ch - '0');
            else if (('a' <= ch) && (ch <= 'z')) {
                string data = str.top();
                str.pop();
                data += ch;
                str.push(data);
            }
            else if (ch == '[') {
                rep.push(tot);
                str.push("");
                tot = 0;
            }
            else if (ch == ']') {
                string suffix = convert(rep.top(), str.top());
                rep.pop();
                str.pop();
                string data = str.top();
                str.pop();
                data += suffix;
                str.push(data);
            }
        }

        return str.top();
    }
private:
    string convert(int rep, string str) {
        string ans = "";
        for (int i = 0; i < rep; i++)
            ans += str;
        return ans;
    }
};
