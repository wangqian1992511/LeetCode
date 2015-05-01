class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n == 1)
            return 0;
        else if (num[0] > num[1])
            return 0;
        else if (num[n-1] > num[n-2])
            return n-1;
        else {
            int l = 1, r = n-2;
            while (l < r) {
                int m = (l + r) >> 1;
                if ((num[m] > num[m+1]) && (num[m] > num[m-1]))
                    return m;
                else if (num[m] > num [m+1])
                    r = m - 1;
                else
                    l = m + 1;
            }
            return l;
        }
    }
};