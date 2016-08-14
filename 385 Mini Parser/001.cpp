/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        num = 0;
        isNeg = false;
        stk.push(NestedInteger());
        for (auto ch: s) {
            switch (ch) {
                case '[': {
                    stk.push(NestedInteger());
                    break;
                }
                case ']': {
                    finishNum();
                    NestedInteger nestNum = stk.top();
                    stk.pop();
                    stk.top().add(nestNum);
                    break;
                }
                case ',': {
                    finishNum();
                    break;
                }
                case '-': {
                    isNeg = true;
                    break;
                }
                default: {
                    hasNum = true;
                    num = num * 10 + int(ch - '0');
                }
            }
        }
        finishNum();
        return stk.top().getList()[0];
    }
private:
    stack<NestedInteger> stk;
    bool hasNum, isNeg;
    int num;
    void finishNum() {
        if (hasNum) {
            stk.top().add(NestedInteger(isNeg ? -num : num));
            hasNum = false;
            isNeg = false;
            num = 0;
        }
    }
};
