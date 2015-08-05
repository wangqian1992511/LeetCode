# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        d = {}
        return self.dfs(node, d)
    def dfs(self, node, d):
        if node is None:
            return None
        if node not in d:
            v = UndirectedGraphNode(node.label)
            d[node] = v
            for u in node.neighbors:
                v.neighbors.append(self.dfs(u, d))
        return d[node]