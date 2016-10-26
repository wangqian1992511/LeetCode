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
        dfs(nestedList, 1);
        maxDep++;

        int ans = 0;
        for (auto it: depToSum) {
            ans += (maxDep - it.first) * it.second;
        }
        return ans;
    }
private:
    int maxDep;
    unordered_map<int, int> depToSum;
    void dfs(vector<NestedInteger>& nestedList, int dep) {
        maxDep = max(maxDep, dep);
        for (auto it: nestedList) {
            if (it.isInteger()) {
                depToSum[dep] += it.getInteger();
            } else {
                dfs(it.getList(), dep + 1);
            }
        }
    }
};
