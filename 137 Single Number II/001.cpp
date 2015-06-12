class Solution {
public:
    int singleNumber(vector<int> &A) {
        int n = A.size();
        int na, nb, a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            na = A[i] & b | ~A[i] & a;
            nb = ~a & (A[i] ^ b);
            a = na;
            b = nb;
        }
        return a | b;
    }
};