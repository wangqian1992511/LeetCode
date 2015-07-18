class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (!n) return 0;
        stack<int> st;
        int *pair = new int [n];
        for (int i = 0; i < n; i++) {
            pair[i] = -1;
            if (s[i] == '(')
                st.push(i);
            else if (!st.empty()) {
                int t = st.top();
                st.pop();
                pair[t] = i;
            }
        }
        int i = 0, tot = 0, ans = 0;
        while (i < n) {
            if (pair[i] > 0) {
                tot += pair[i] - i + 1;
                i = pair[i] + 1;
            }
            else {
                ans = max(ans, tot);
                tot = 0;
                i++;
            }
        }
        return max(ans, tot);
    }
};