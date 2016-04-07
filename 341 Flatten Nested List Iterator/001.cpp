/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it = nestedList.begin();
        term = nestedList.end();
    }
    
    int next() {
        int ans = s.top().getInteger();
        s.pop();
        return ans;
    }
    
    bool hasNext() {
        if (s.empty() && (it == term))
            return false;
        if (s.empty()) {
            s.push(*it);
            it++;
        }
        while (!s.empty() && !s.top().isInteger()) {
            vector<NestedInteger> x = s.top().getList();
            s.pop();
            for (auto it = x.rbegin(); it != x.rend(); it++)
                s.push(*it);
        }
        return s.empty() ? hasNext() : true;
    }
private:
    vector<NestedInteger>::iterator it, term;
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */