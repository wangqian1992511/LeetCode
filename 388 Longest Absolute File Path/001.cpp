class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream stringIn(input);
        int ans = 0, tmp = 0;
        stack<int> st;
        string s;

        while (getline(stringIn, s)) {
            int idx = s.find_last_of('\t') + 1;
            while (idx < st.size()) {
                tmp -= st.top();
                st.pop();
            }
            string name = s.substr(idx);
            st.push(name.size());
            tmp += name.size();
            if (name.find_first_of('.') != -1) {
                ans = max(ans, tmp + int(st.size()) - 1);
            }
        }

        return ans;
    }
};
