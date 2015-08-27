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
                    edge[s[j]].emplace(t[j]);
                    break;
                }
        }
        
        int deg[26];
        fill(deg, deg + 26, 0);
        for (auto e = edge.begin(); e != edge.end(); e++)
            for (auto y = e->second.begin(); y != e->second.end(); y++)
                deg[*y - 'a']++;
                
        unordered_set<char> cand;
        for (int i = 0; i < n; i++)
            for (auto ch: words[i])
                cand.emplace(ch);
        n = cand.size();
                        
        queue<char> q;  
        for (auto ch = cand.begin(); ch != cand.end(); ch++)
            if (!deg[*ch - 'a'])
                q.push(*ch);
        
        string st = "";
        while (!q.empty()) {
            char x = q.front();
            q.pop();
            st += x;
            for (auto e = edge[x].begin(); e != edge[x].end(); e++) {
                deg[*e - 'a']--;
                if (!deg[*e - 'a'])
                    q.push(*e);
            }
        }
        
        return st.size() == n ? st : "";
    }
};