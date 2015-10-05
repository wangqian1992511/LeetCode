class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto it = dictionary.begin(); it != dictionary.end(); it++) {
            s.insert(*it);
            cnt[convert(*it)]++;
        }
    }

    bool isUnique(string word) {
        return (s.find(word) == s.end()) && !cnt[convert(word)] ||
               (s.find(word) != s.end()) && (cnt[convert(word)] == 1);
    }
private:
    unordered_set<string> s;
    unordered_map<string, int> cnt;
    string convert(string str) {
        if (str.size() <= 2) return str;
        string ans = "";
        ans += str[0];
        ans += to_string(str.size() - 2);
        ans += str[str.size() - 1];
        return ans;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
