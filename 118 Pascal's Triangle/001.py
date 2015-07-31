class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        ans = []
        if numRows == 0:
            return ans
        ans.append([1])
        for i in range(1, numRows):
            ans.append([1])
            for j in range(1, i):
                ans[i].append(ans[i-1][j] + ans[i-1][j-1])
            ans[i].append(1)
        return ans