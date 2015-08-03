class Solution:
    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solve(self, board):
        n = len(board)
        if n == 0:
            return
        m = len(board[0])
        if m == 0:
            return
        vis = [[board[i][j] == 'X' for j in range(m)] for i in range(n)]
        q = []
        for j in range(m):
            if board[0][j] == 'O':
                q.append([0, j])
            if board[n-1][j] == 'O':
                q.append([n-1, j])
        for i in range(n):
            if board[i][0] == 'O':
                q.append([i, 0])
            if board[i][m-1] == 'O':
                q.append([i, m-1])
        while len(q) > 0:
            x, y = q.pop()
            vis[x][y] = True
            if self.isValid(x + 1, y, n, m, vis):
                q.append([x + 1, y])
            if self.isValid(x - 1, y, n, m, vis):
                q.append([x - 1, y])
            if self.isValid(x, y + 1, n, m, vis):
                q.append([x, y + 1]) 
            if self.isValid(x, y - 1, n, m, vis):
                q.append([x, y - 1])                 
        for i in range(n):
            for j in range(m):
                if not vis[i][j]:
                    board[i][j] = 'X'
    def isValid(self, i, j, n, m, vis):
        if i < 0 or j < 0 or i >= n or j >= m or vis[i][j]:
            return False
        return True