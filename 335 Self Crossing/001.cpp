class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n <= 3)
            return false;
        
        int p = 2;
        while ((p < n) && (x[p] > x[p - 2]))
            p++;
        
        if ((p < n) && (x[p] + (p >= 4 ? x[p - 4] : 0) >= x[p - 2]))
            x[p - 1] -= x[p - 3];
        
        p++;
        while ((p < n) && (x[p] < x[p - 2]))
            p++;
        
        return p < n;
    }
};