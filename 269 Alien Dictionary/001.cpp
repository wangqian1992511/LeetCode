class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> edge;
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string s = words[i], t = words[i + 1];
            int l = min(s.size(), t.size());
            for (int j = 0; j < l; j++)
                if (s[j] != t[j]) {
                    edge[s[j]].insert(t[j]);
                    break;
                }
        }

        unordered_map<char, int> deg;
        for (auto e: edge)
            for (auto u: e.second)
                deg[u]++;

        unordered_set<char> cand;
        queue<char> q;
        for (auto s: words)
            for (auto ch: s)
                if (!cand.count(ch)) {
                    cand.insert(ch);
                    if (!deg[ch])
                        q.push(ch);
                }

        string st = "";
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            st.push_back(u);
            for (auto v: edge[u]) {
                deg[v]--;
                if (!deg[v])
                    q.push(v);
            }
        }

        return st.size() == cand.size() ? st : "";
    }
};
