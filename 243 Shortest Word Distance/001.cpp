class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        idx1 = idx2 = -1;
        pt = 0;
        this->word1 = word1;
        this->word2 = word2;
        wordsIt = words.begin();

        while ((idx1 < 0) || (idx2 < 0)) {
            updateIt();
        }

        int ans = abs(idx1 - idx2);
        while (wordsIt != words.end()) {
            updateIt();
            ans = min(ans, abs(idx1 - idx2));
        }

        return ans;
    }
private:
    string word1, word2;
    int idx1, idx2, pt;
    vector<string>::iterator wordsIt;

    void updateIt() {
        if (*wordsIt == word1) {
            idx1 = pt;
        } else if (*wordsIt == word2) {
            idx2 = pt;
        }
        wordsIt++;
        pt++;
    }
};
