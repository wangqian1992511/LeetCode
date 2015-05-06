class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> *adj = new vector<int> [numCourses];
        int *deg = new int [numCourses];
        bool *vis = new bool [numCourses];
        fill(deg, deg + numCourses, 0);
        fill(vis, vis + numCourses, 0);
        
        int nEdge = prerequisites.size();
        for (int i = 0; i < nEdge; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            deg[prerequisites[i][1]]++;
        }
        
        queue<int> zero;
        for (int i = numCourses - 1; i >= 0; i--) 
            if (!deg[i]) {
                zero.push(i);
                vis[i] = true;
            }
        
        int d = 0, u, v, n; 
        while (!zero.empty()) {
            u = zero.front();
            n = adj[u].size();
            zero.pop();
            d++;
            for (int j = 0; j < n; j++) {
                v = adj[u][j];
                deg[v]--;
                if (!deg[v] && !vis[v])
                    zero.push(v);
            }
        }
        return d == numCourses;
    }
};