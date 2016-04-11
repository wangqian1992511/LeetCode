class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++)
            hash[words[i]] = i;
        for (int i = 0; i < n; i++) {
            string now = words[i];
            
            if (isPalin(now) && (hash.find("") != hash.end()) && (hash[""] != i)) {
                ans.push_back({i, hash[""]});
                ans.push_back({hash[""], i});
            }
            
            int m = now.size();
            for (int j = 1; j < m; j++) {
                string other = now.substr(0, j);
                reverse(other.begin(), other.end());
                if (isPalin(now + other) && (hash.find(other) != hash.end()) && (hash[other] != i))
                    ans.push_back({i, hash[other]});
                
                other = now.substr(m - j, j);
                reverse(other.begin(), other.end());
                if (isPalin(other + now) && (hash.find(other) != hash.end()) && (hash[other] != i))
                    ans.push_back({hash[other], i});
            }
            
            string other = now;
            reverse(other.begin(), other.end());
            if (isPalin(now + other) && (hash.find(other) != hash.end()) && (hash[other] != i))
                ans.push_back({i, hash[other]});
        }
        return ans;
    }
private:
    int n;
    vector<vector<int>> ans;
    unordered_map<string, int> hash;
    bool isPalin(string st) {
        int n = st.size();
        for (int i = 0; i < n / 2; i++)
            if (st[i] != st[n - 1 - i])
                return false;
        return true;
    }
};