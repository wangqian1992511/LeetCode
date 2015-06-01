class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordDict) {
        int n = beginWord.size();
        now.push_back(beginWord);
        
        wordDict.erase(beginWord);
        wordDict.emplace(endWord);
            
        queue<vector<string>> q[2];
        unordered_set<string> clr;
        bool ptr = false, stop = false;
        q[ptr].push(now);
        
        while (!q[ptr].empty()) {
            now = q[ptr].front();
            q[ptr].pop();
            for (int i = 0; i < n; i++)
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string t = now.back();
                    t[i] = ch;
                    if (wordDict.find(t) != wordDict.end()) {
                        now.push_back(t);
                        if (t == endWord){
                            stop = true;
                            ans.push_back(now);
                        }
                        else if (!stop) {
                            q[!ptr].push(now);
                            clr.emplace(t);
                        }
                        now.pop_back();
                    }
                }
            
            if (q[ptr].empty()) {
                if (stop)
                    return ans;
                ptr = !ptr;
                for (auto it = clr.begin(); it != clr.end(); it++)
                    wordDict.erase(*it);
                clr.clear();
            }
        }
        
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> now;
};