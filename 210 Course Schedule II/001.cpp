class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> *adj = new vector<int> [numCourses];
        int *deg = new int [numCourses];
        fill(deg, deg + numCourses, 0);
        
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++) {
            adj[it->second].push_back(it->first);
            deg[it->first]++;
        }
        
        queue<int> zero;
        for (int i = numCourses - 1; i >= 0; i--) 
            if (!deg[i]) 
                zero.push(i);
                
        int u, v; 
        vector<int> ans;
        while (!zero.empty()) {
            u = zero.front();
            zero.pop();
            ans.push_back(u);
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) 
                if (! --deg[*it])
                    zero.push(*it);
        }        
        if (ans.size() != numCourses)
            ans.clear();
        return ans;
    }
};