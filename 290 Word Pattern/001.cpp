class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hashA;
        unordered_map<string, char> hashB;
        istringstream sinit (str);
        int n = pattern.size();
        string word;
        for (int i = 0; i < n; i++) 
            if (sinit >> word) {
                char ch = pattern[i];
                if (hashA.find(ch) == hashA.end())
                    hashA[ch] = word;
                else if (hashA[ch] != word)
                    return false;
                if (hashB.find(word) == hashB.end())
                    hashB[word] = ch;
                else if (hashB[word] != ch)
                    return false;
            }
            else
                return false;
        return !(sinit >> word);
    }
};
