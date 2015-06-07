/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode *ans = NULL;
        
        if (node) {
            q.push(node);
            ans = new UndirectedGraphNode (node->label);
            hash[node] = ans;
        }
        
        while (!q.empty()) {
            UndirectedGraphNode *v = q.front();
            UndirectedGraphNode *r = hash[v];
            UndirectedGraphNode *s;
            
            int n = v->neighbors.size();
            for (int i = 0; i < n; i++) {
                if (hash.find(v->neighbors[i]) != hash.end()) 
                    s = hash[v->neighbors[i]];
                else {
                    s = new UndirectedGraphNode (v->neighbors[i]->label);
                    hash[v->neighbors[i]] = s;
                    q.push(v->neighbors[i]);
                }
                r->neighbors.push_back(s);
            }
            
            q.pop();
        }
        
        return ans;
    }
};