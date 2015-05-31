class Solution {
public:
    int searchInsert(vector<int> A, int target) {
        int n = A.size();
        int left = 0;
        int right = n-1;
        
        if (A[right] < target) return n;
        if (A[left] >= target) return 0;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A [mid] == target)
                return mid;
            if (A[mid] > target)
                right = mid - 1;
            if (A[mid] < target)
                left = mid + 1;
        }
        
        if (A[right] > target) return right;
        if (A[right] < target) return right + 1;
    }
};
