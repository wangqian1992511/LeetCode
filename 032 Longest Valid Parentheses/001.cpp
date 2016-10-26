class Solution {
public:
    int longestValidParentheses(string s) {
        buildPair(s);
        int current = 0, ans = 0, idx = 0;
        while (idx < s.size()) {
            if (pair.count(idx)) {
                current += pair[idx] - idx + 1;
                idx = pair[idx] + 1;
            } else {
                ans = max(ans, current);
                current = 0;
                idx++;
            }
        }
        return max(ans, current);
    }
private:
    unordered_map<int, int> pair;
    void buildPair(string &s) {
        stack<int> st;
        int idx = 0;
        for (auto ch: s) {
            if (ch == '(')
                st.push(idx);
            else if (!st.empty()) {
                pair[st.top()] = idx;
                st.pop();
            }
            idx++;
        }
    }
};
