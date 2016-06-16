class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k <= 1)
            return str;
        int n = str.size();

        unordered_map<char, int> cnt;
        for (auto ch: str)
            cnt[ch]++;

        map<int, vector<char>> sortedCnt;
        for (auto it: cnt)
            sortedCnt[-it.second].push_back(it.first);

        string ans(str.size(), '@');
        int p = 0, round = 0;
        for (auto it: sortedCnt) {
            if (k * (-it.first - 1) + it.second.size() > n)
                return "";
            int maxN = -it.first;
            for (auto ch: it.second) {
                for (int i = 0; i < maxN; i++) {
                    ans[p] = ch;
                    p += k;
                    if (p >= n) {
                        round++;
                        p = round;
                    }
                }
            }
        }
        return ans;
    }
};
