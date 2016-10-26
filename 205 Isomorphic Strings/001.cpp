class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> sToT, tToS;
        string::iterator sIt = s.begin();
        string::iterator tIt = t.begin();
        while (sIt != s.end()) {
            bool sMapped = sToT.count(*sIt);
            bool tMapped = tToS.count(*tIt);
            if (sMapped != tMapped)
                return false;
            else if (!sMapped) {
                sToT[*sIt] = *tIt;
                tToS[*tIt] = *sIt;
            }
            else if (sToT[*sIt] != *tIt)
                return false;
            else if (tToS[*tIt] != *sIt)
                return false;
            sIt++;
            tIt++;
        }
        return true;
    }
};
