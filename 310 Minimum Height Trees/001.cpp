class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> *adj = new vector<int> [n];
        int *deg = new int [n];
        fill(deg, deg + n, 0);
        for (auto it = edges.begin(); it != edges.end(); it++) {
            adj[it->first].push_back(it->second);
            adj[it->second].push_back(it->first);
            deg[it->first]++;
            deg[it->second]++;
        }
        
        bool *vis = new bool [n];
        int *lvl = new int [n];
        fill(vis, vis + n, false);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 1) {
                q.push(i);
                lvl[i] = 0;
            }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                deg[*it]--;
                if (deg[*it] == 1) {
                    q.push(*it);
                    lvl[*it] = lvl[u] + 1;
                }
            }
        }
        
        int maxV = -1;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (lvl[i] > maxV)
                maxV = lvl[i];
        for (int i = 0; i < n; i++)
            if (lvl[i] == maxV)
                ans.push_back(i);
        return ans;
    }
};