// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = (int64_t(l) + r) >> 1;
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};