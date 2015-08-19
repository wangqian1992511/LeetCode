class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int p, ans = INT_MAX;
        bool one = false, two = false;
        for (int i = 0; i < n; i++)
            if (words[i] == word1) {
                if (two)
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