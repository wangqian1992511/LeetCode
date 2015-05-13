class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> *adj = new vector<int> [numCourses];
        int *deg = new int [numCourses];
        fill(deg, deg + numCourses, 0);

        for (int i = prerequisites.size() - 1; i >= 0; i--) {
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
            deg[prerequisites[i].second]++;
        }
        
        queue<int> zero;
        for (int i = numCourses - 1; i >= 0; i--) 
            if (!deg[i]) 
                zero.push(i);
        
        int d = 0, u, v, n; 
        while (!zero.empty()) {
            u = zero.front();
            n = adj[u].size();
            zero.pop();
            d++;
            for (int j = 0; j < n; j++) {
                v = adj[u][j];
                if (! --deg[v]) 
                    zero.push(v);
            }
        }
        return d == numCourses;    
    }
};
