class Solution {
public:
    vector<vector<string>> findLadders(string &beginWord, string &endWord, unordered_set<string> &wordList) {
        wordList.erase(endWord);
        wordList.erase(beginWord);
        wordLen = endWord.size();

        flag[true] = true;
        q[true][true].push(endWord);
        inQ[true].insert(endWord);
        canUse.insert(endWord);

        flag[false] = true;
        q[false][true].push(beginWord);
        inQ[false].insert(beginWord);

        while (!q[true][flag[true]].empty()) {
            if (expand(wordList, true))
                break;
            if (expand(wordList, false))
                break;
        }

        buildPath(endWord, beginWord);
        return ans;
    }
private:
    int wordLen;

    queue<string> q[2][2];
    unordered_set<string> canUse, inQ[2];
    bool flag[2];

    unordered_map<string, vector<string>> pre;
    vector<vector<string>> ans;
    vector<string> path;

    bool expand(unordered_set<string> &wordList, bool toBack) {
        bool meet = false;
        bool f = flag[toBack];
        while (!q[toBack][f].empty()) {
            string thisWord = q[toBack][f].front();
            q[toBack][f].pop();
            for (int i = 0; i < wordLen; i++) {
                string nextWord = thisWord;
                char tc = thisWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == tc) continue;
                    nextWord[i] = ch;
                    if (wordList.count(nextWord)) {
                        wordList.erase(nextWord);
                        q[toBack][!f].push(nextWord);
                        inQ[toBack].insert(nextWord);
                        canUse.insert(nextWord);
                    }
                    else if (inQ[!toBack].count(nextWord))
                        meet = true;
                    else if (!canUse.count(nextWord))
                        continue;
                    if (toBack)
                        pre[nextWord].push_back(thisWord);
                    else
                        pre[thisWord].push_back(nextWord);
                }
            }
        }
        canUse.clear();
        flag[toBack] = !f;
        return meet;
    }

    void buildPath(string &beginWord, string &endWord) {
        path.push_back(endWord);
        if (beginWord == endWord)
            ans.push_back(path);
        else
            for (auto preWord: pre[endWord])
                buildPath(beginWord, preWord);
        path.pop_back();
    }
};
