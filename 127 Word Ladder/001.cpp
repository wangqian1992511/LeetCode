struct pathT {
    string data;
    int dep;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int n = beginWord.size();
        wordDict.erase(beginWord);
        wordDict.emplace(endWord);
            
        queue<pathT> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            pathT x = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string t = x.data;
                    t[i] = ch;
                    if (wordDict.find(t) != wordDict.end()) {
                        if (t == endWord)
                            return x.dep + 1;
                        q.push({t, x.dep + 1});
                        wordDict.erase(t);
                    }
                }
        }
        return 0;
    }
};