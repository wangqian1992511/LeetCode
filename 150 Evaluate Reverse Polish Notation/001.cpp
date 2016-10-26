class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (auto it: tokens) {
            if (it == "+") {
                updateNum();
                nums.push(x + y);
            } else if (it == "-") {
                updateNum();
                nums.push(x - y);
            } else if (it == "*") {
                updateNum();
                nums.push(x * y);
            } else if (it == "/") {
                updateNum();
                nums.push(x / y);
            } else {
                nums.push(stoi(it));
            }
        }
        return nums.top();
    }
private:
    stack<int> nums;
    int x, y;
    void updateNum() {
        y = nums.top();
        nums.pop();
        x = nums.top();
        nums.pop();
    }
};
