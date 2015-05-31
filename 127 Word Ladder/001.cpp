struct pathT {
    string data;
    int dep;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<pathT> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            pathT x = q.front();
            if (calcDist(x.data, endWord) == 1)
                return x.dep + 1;
            q.pop();
            for (int i = 0; i < x.data.size(); i++)
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string t = x.data;
                    t[i] = ch;
                    if (wordDict.find(t) != wordDict.end()) {
                        q.push({t, x.dep + 1});
                        wordDict.erase(t);
                    }
                }
        }
        return 0;
    }
private:
    int calcDist(string s, string t) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += (s[i] != t[i]);
        return ans;
    }
};
