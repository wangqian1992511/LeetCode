class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++)
            pos[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        auto va = pos[word1].begin();
        auto vb = pos[word2].begin();
        int ans = INT_MAX;
        while ((va != pos[word1].end()) && (vb != pos[word2].end())) {
            ans = min(ans, abs(*va - *vb));
            if (*va < *vb) 
                va++;
            else
                vb++;
        }
        return ans;
    }
private:
    unordered_map<string, vector<int>> pos;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");