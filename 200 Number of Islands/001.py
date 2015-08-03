class Solution:
    # @param {character[][]} grid
    # @return {integer}
    def numIslands(self, grid):
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        if m == 0:
            return 0
        vis = [[grid[i][j] == '0' for j in range(m)] for i in range(n)]
        ans = 0
        for i in range(n):
            for j in range(m):
                if not vis[i][j]:
                    self.dfs(i, j, vis)
                    ans += 1
        return ans
    def dfs(self, i, j, vis):
        if i < 0 or j < 0 or i >= len(vis) or j >= len(vis[0]) or vis[i][j]:
            return
        vis[i][j] = True
        self.dfs(i + 1, j, vis)
        self.dfs(i, j + 1, vis)
        self.dfs(i - 1, j, vis)
        self.dfs(i, j - 1, vis)