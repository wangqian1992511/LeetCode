class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int p, ans = INT_MAX;
        bool one = false, two = false, same = (word1 == word2);
        for (int i = 0; i < n; i++)
            if (words[i] == word1) {
                if (two || same && one)
                    ans = min(ans, i - p);
                p = i;
                one = true;
                two = false;
            }
            else if (words[i] == word2) {
                if (one)
                    ans = min(ans, i - p);
                p = i;
                two = true;
                one = false;
            }
        return ans;
    }
};