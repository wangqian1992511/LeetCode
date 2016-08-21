class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int len = beginWord.size();
        wordList.insert(endWord);
        wordList.erase(beginWord);

        unordered_map<string, int> dep;
        dep[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty() && wordList.count(endWord)) {
            string s = q.front();
            q.pop();
            for (int i = 0; i < len; i++) {
                string t = s;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (s[i] == ch)
                        continue;
                    t[i] = ch;
                    if (wordList.count(t)) {
                        wordList.erase(t);
                        dep[t] = dep[s] + 1;
                        q.push(t);
                    }
                }
            }
        }
        return dep[endWord];
    }
};
