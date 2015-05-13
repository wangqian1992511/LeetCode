class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> *adj = new vector<int> [numCourses];
        int *deg = new int [numCourses];
        fill(deg, deg + numCourses, 0);
        
        for (int i = prerequisites.size() - 1; i >= 0; i--) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            deg[prerequisites[i].first]++;
        }
        
        queue<int> zero;
        for (int i = numCourses - 1; i >= 0; i--) 
            if (!deg[i]) 
                zero.push(i);
                
        int u, v, n; 
        vector<int> ans;
        while (!zero.empty()) {
            u = zero.front();
            n = adj[u].size();
            zero.pop();
            ans.push_back(u);
            for (int j = 0; j < n; j++) {
                v = adj[u][j];
                if (! --deg[v]) 
                    zero.push(v);
            }
        }        
        if (ans.size() != numCourses)
            ans.clear();
        return ans;
    }
};