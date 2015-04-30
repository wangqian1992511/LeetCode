class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[256], org[256];
        fill(map, map+256, -1);
        fill(org, org+256, -1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char sc = s[i], tc = t[i];
            if ((map[sc] == -1) && (org[tc] == -1)) {
                map[sc] = tc;
                org[tc] = sc;
            }
            else if (map[sc] != tc)
                return false;
        }
        return true;
    }
};