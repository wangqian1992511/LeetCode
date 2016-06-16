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

        pair<int, vector<char>> head = *sortedCnt.begin();
        if (k * (-head.first - 1) + head.second.size() > n)
            return "";

        string ans(str.size(), '@');
        int p = 0, round = 0;
        for (auto it: sortedCnt) {
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
