class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, queue<int>> hash;
        int idx = 0;
        for (auto ch: t)
            hash[ch].push(idx++);

        int minPossibleIdx = 0;
        for (auto ch: s) {
            while (!hash[ch].empty() && (hash[ch].front() < minPossibleIdx))
                hash[ch].pop();
            if (hash[ch].empty())
                return false;
            minPossibleIdx = hash[ch].front() + 1;
        }

        return true;
    }
};
