class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        int pt = 0;
        string st = strs[0];
        while (pt < st.size()) {
            char ch = st[pt];
            for (auto it: strs)
                if ((pt == it.size()) || (ch != it[pt]))
                    return st.substr(0, pt);
            pt++;
        }
        return st.substr(0, pt);
    }
};
