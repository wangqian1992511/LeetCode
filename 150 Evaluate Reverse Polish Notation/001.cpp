class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string str = tokens[i];
            if (str == "+") {
                popTwo();
                s.push(b + a);               
            }
            else if (str == "-") {
                popTwo();
                s.push(b - a); 
            }
            else if (str == "*") {
                popTwo();
                s.push(b * a); 
            }
            else if (str == "/") {
                popTwo();
                s.push(b / a); 
            }
            else 
                s.push(atoi(str.c_str()));
        }
        return s.top();
    }
private:
    stack<int> s;
    int a, b;
    void popTwo() {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
    }
};