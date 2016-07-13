class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto it: dictionary)
            if (!s.count(it)) {
                s.insert(it);
                cnt[convert(it)]++;
            }
    }

    bool isUnique(string word) {
        return s.count(word) == cnt[convert(word)];
    }
private:
    unordered_set<string> s;
    unordered_map<string, int> cnt;
    string convert(string str) {
        if (str.size() <= 2) return str;
        return str[0] + to_string(str.size() - 2) + str[str.size() - 1];
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
