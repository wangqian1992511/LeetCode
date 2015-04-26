class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for (int i = 0; i < n; i++) 
            while ((A[i] == elem) && (i < n)) {
                A[i] = A[n-1];
                n--;
            }
        return n;
    }
};