class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordDict) {
        int n = beginWord.size();
		queue<string> q[2];
        unordered_set<string> clr;
        unordered_map<string, bool> inQ;
        for (auto it = wordDict.begin(); it != wordDict.end(); it++)
			inQ[*it] = false;
        bool ptr = false, stop = false;
		
		wordDict.erase(beginWord);
		wordDict.emplace(endWord);
        q[ptr].push(beginWord);
        inQ[beginWord] = true;
        
        while (!q[ptr].empty()) {
            string s = q[ptr].front();
            q[ptr].pop();
			for (int i = 0; i < n; i++)
                for (char ch = 'a'; ch <= 'z'; ch++) {
					string t = s;
					t[i] = ch;
					if (wordDict.find(t) != wordDict.end()) {
    				    path[t].push_back(s);
    					if (t == endWord)
    						stop = true;
    					else if (!inQ[t]) {
    						q[!ptr].push(t);
    						inQ[t] = true;
    						clr.emplace(t);
    					}
    				}
                }
            
            if (q[ptr].empty()) {
                if (stop)
                    break;
                ptr = !ptr;
                for (auto it = clr.begin(); it != clr.end(); it++)
                    wordDict.erase(*it);
                clr.clear();
            }
        }
        
        return buildPath(beginWord, endWord);
    }
private:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> path;
    vector<vector<string>> buildPath(string st, string en) {
        vector<vector<string>> ans;
        if (st == en) {
            vector<string> now;
            now.push_back(st);
            ans.push_back(now);
            return ans;
        }
        vector<string> prev = path[en];
        int n = prev.size();
        for (int i = 0; i < n; i++) {
            vector<vector<string>> now = buildPath(st, prev[i]);
            int m = now.size();
            for (int j = 0; j < m; j++) {
                now[j].push_back(en);
                ans.push_back(now[j]);
            }
        }
        return ans;
    }    
};