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
        fill(vis, vis + n, false);
        queue<int> q[2];
        for (int i = 0; i < n; i++)
            if (deg[i] <= 1)
                q[0].push(i);
        
        vector<int> ans;
        bool flag = false;
        while (!q[flag].empty()) {
            ans.clear();
            while (!q[flag].empty()) {
                int u = q[flag].front();
                q[flag].pop();
                ans.push_back(u);
                for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                    deg[*it]--;
                    if (deg[*it] == 1)
                        q[!flag].push(*it);
                }
            }
            flag = !flag;
        }
        return ans;
    }
    
};