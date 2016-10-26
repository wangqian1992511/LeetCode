class Solution {
public:
    bool isValid(string s) {
        for (auto ch: s) {
            switch(ch) {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                    if (!updateStack('('))
                        return false;
                    break;
                case ']':
                    if (!updateStack('['))
                        return false;
                    break;
                case '}':
                    if (!updateStack('{'))
                        return false;
                    break;
            }
        }
        return st.empty();
    }
private:
    stack<char> st;
    bool updateStack(char ch) {
        if (!st.empty() && (st.top() == ch)) {
            st.pop();
            return true;
        }
        return false;
    }
};
