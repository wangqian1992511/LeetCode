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
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, getDepth(nestedList));
    }
private:
    int getDepth(vector<NestedInteger>& nestedList) {
        int ans = 1;
        for (auto it: nestedList)
            if (!it.isInteger())
                ans = max(ans, 1 + getDepth(it.getList()));
        return ans;
    }
    int dfs(vector<NestedInteger>& nestedList, int dep) {
        int ans = 0;
        for (auto it: nestedList)
            if (it.isInteger())
                ans += it.getInteger() * dep;
            else
                ans += dfs(it.getList(), dep - 1);
        return ans;
    }
};
