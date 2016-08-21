class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int len = beginWord.size();
        wordList.insert(endWord);
        wordList.erase(beginWord);

        queue<string> q;
        unordered_set<string> atThisLevel;
        q.push(beginWord);
        while (!q.empty() && !atThisLevel.count(endWord)) {
            int n = q.size();
            atThisLevel.clear();
            for (int k = 0; k < n; k++) {
                string s = q.front();
                q.pop();
                for (int i = 0; i < len; i++) {
                    string t = s;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (s[i] == ch)
                            continue;
                        t[i] = ch;
                        if (wordList.count(t) || atThisLevel.count(t)) {
                            if (wordList.count(t)) {
                                wordList.erase(t);
                                atThisLevel.insert(t);
                                q.push(t);
                            }
                            next[s].push_back(t);
                        }
                    }
                }
            }
        }
        buildPath(beginWord, endWord);
        return ans;
    }
private:
    unordered_map<string, vector<string>> next;
    vector<vector<string>> ans;
    vector<string> path;
    void buildPath(string beginWord, string endWord) {
        path.push_back(beginWord);
        if (beginWord == endWord)
            ans.push_back(path);
        else for (auto it: next[beginWord])
            buildPath(it, endWord);
        path.pop_back();
    }
};
