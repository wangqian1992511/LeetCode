class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int n = A.size();
        if (!n) return 0;
            
        int l = 1, now = A[0];
        bool twice = false;
        for (int i = 1; i < n; i++){
            if (A[i] != now){
                A[l++] = A[i];
                now = A[i];
                twice = false;
            }
            else if (! twice) {
                A[l++] = now;
                twice = true;
            }
        }
        
        return l;
    }
};
