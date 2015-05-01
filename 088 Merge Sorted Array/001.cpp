class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pA = 0, pB = 0, pC = 0;
        int *C = new int [n+m];
        while ((pA < m) && (pB < n)) {
            if (A[pA] <= B[pB])
                C[pC++] = A[pA++];
            else 
                C[pC++] = B[pB++];
        }
        while (pA < m)
            C[pC++] = A[pA++];
        while (pB < n)
            C[pC++] = B[pB++];
        for (int i = 0; i < n+m; i++)
            A[i] = C[i];
    }
};