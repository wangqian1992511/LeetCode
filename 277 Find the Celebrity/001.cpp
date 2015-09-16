// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> cand;
        for (int i = 0; i < n; i++)
            cand.emplace(i);
        for (int i = 1; i < n; i++) {
            auto it = cand.begin();
            int a = *it;
            it++;
            int b = *it;
            if (knows(a, b))
                cand.erase(a);
            else
                cand.erase(b);
        }
        int t = *cand.begin();
        for (int i = 0; i < n; i++)
            if ((i != t) && (!knows(i, t) || knows(t, i)))
                return -1;
        return t;
    }
};