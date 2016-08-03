class Solution:
    # @param {integer} numCourses
    # @param {integer[][]} prerequisites
    # @return {boolean}
    def canFinish(self, numCourses, prerequisites):
        dgr = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for y, x in prerequisites:
            dgr[y] += 1
            adj[x].append(y)
        q = []
        tot = 0
        for i in range(numCourses):
            if dgr[i] == 0:
                q.append(i)
        while len(q) > 0:
            x = q.pop()
            tot += 1
            while len(adj[x]) > 0:
                y = adj[x].pop()
                dgr[y] -= 1
                if dgr[y] == 0:
                    q.append(y)
        return tot == numCourses
