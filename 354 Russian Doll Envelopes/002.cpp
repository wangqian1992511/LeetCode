class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (!n) return 0;

        vector<int> *adj = new vector<int> [n];
        int *deg = new int [n];
        fill(deg, deg + n, 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isSmaller(envelopes[i], envelopes[j])) {
                    adj[i].push_back(j);
                    deg[j]++;
                }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!deg[i])
                q.push(i);

        int* len = new int [n], ans = 1;
        fill(len, len + n, 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans = max(len[u], ans);
            for (auto v: adj[u]) {
                len[v] = max(len[v], len[u] + 1);
                deg[v]--;
                if (!deg[v])
                    q.push(v);
            }
        }

        return ans;
    }
private:
    bool isSmaller(pair<int, int> &a, pair<int, int> &b) {
        if (a.first >= b.first) return false;
        if (a.second >= b.second) return false;
        return true;
    }
};
