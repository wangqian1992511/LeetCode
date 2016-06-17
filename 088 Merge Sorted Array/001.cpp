class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--; n--;
        int r = m + n + 1;
        while ((m >= 0) && (n >= 0))
            if (nums1[m] < nums2[n])
                nums1[r--] = nums2[n--];
            else
                nums1[r--] = nums1[m--];
        while (m >= 0)
            nums1[r--] = nums1[m--];
        while (n >= 0)
            nums1[r--] = nums2[n--];
    }
};
