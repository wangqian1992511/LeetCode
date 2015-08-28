class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for (auto word = strs.begin(); word != strs.end(); word++) {
            for (auto ch: *word)
                if (ch == 0x7D || ch == 0x7E) {
                    ans += char(0x7D);
                    ans += char(ch ^ 0x20);
                }
                else 
                    ans += ch;
            ans += char(0x7E);
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string tmp = "";
        bool flag = false;
        for (auto ch: s)
            if (ch == 0x7E) {
                ans.push_back(tmp);
                tmp = "";
            }
            else if (ch == 0x7D) 
                flag = true;
            else if (flag) {
                tmp += char(ch ^ 0x20);
                flag = false;
            }
            else
                tmp += ch;
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));