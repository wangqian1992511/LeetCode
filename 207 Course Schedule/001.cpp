class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> *adj = new vector<int> [numCourses];
        int *deg = new int [numCourses];
        fill(deg, deg + numCourses, 0);

        for (auto it: prerequisites) {
            adj[it.second].push_back(it.first);
            deg[it.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!deg[i])
                q.push(i);

        int d = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            d++;
            for (auto v: adj[u]) {
                if (! --deg[v])
                    q.push(v);
            }
        }
        return d == numCourses;
    }
};
