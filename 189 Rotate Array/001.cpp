class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) k = k % n;
        if (!k) return;
        int t = gcd(n,k);
        for (int i = 0; i < t; i++) {
            int p = i;
            int next = nums[i];
            do {
                p = (p + k) % n;
                int tmp = nums[p];
                nums[p] = next;
                next = tmp;
            } while (p != i);
        }
    }
private:
    int gcd(int a, int b) {
        if (b) return gcd(b, a % b);
        return a;
    }    
};