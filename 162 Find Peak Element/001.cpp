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
            for (int i = 1; i < n-1; i++)
                if ((num[i] > num[i-1]) && (num[i] > num[i+1]))
                    return i;
        }
    }
};