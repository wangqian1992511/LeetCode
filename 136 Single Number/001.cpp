class Solution {
public:
    int singleNumber(vector<int> &A) {
        int k = 0, n = A.size();
        for (int i = 0; i < n; i++)
            k ^= A[i];
        return k;
    }
};