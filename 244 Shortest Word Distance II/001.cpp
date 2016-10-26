class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int idx = 0;
        for (auto it: words) {
            index[it].push_back(idx++);
        }
    }

    int shortest(string word1, string word2) {
        if (!solutions.count(word1) || !solutions[word1].count(word2)) {
            int x = calcDist(word1, word2);
            solutions[word1][word2] = x;
            solutions[word2][word1] = x;
            return x;
        }
        return solutions[word1][word2];
    }
private:
    unordered_map<string, unordered_map<string, int>> solutions;
    unordered_map<string, vector<int>> index;

    int calcDist(string& word1, string& word2) {
        vector<int>::iterator word1It = index[word1].begin();
        vector<int>::iterator word2It = index[word2].begin();
        int ans = INT_MAX;
        while ((word1It != index[word1].end()) && (word2It != index[word2].end())) {
            ans = min(ans, abs(*word1It - *word2It));
            if (*word1It < *word2It) {
                word1It++;
            } else {
                word2It++;
            }
        }
        return ans;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
