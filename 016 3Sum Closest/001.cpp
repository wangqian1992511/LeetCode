class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
		sort(num.begin(), num.end());
        int ans = 0, tmp = INT_MAX;
        for (int i = 0; i <= n-3; i++) {
            int p = i + 1;
            int q = n - 1;
            while (p < q) {
                if (abs(num[i] + num[p] + num[q] - target) < tmp) {
                    tmp = abs(num[i] + num[p] + num[q] - target);
                    ans = num[i] + num[p] + num[q];
                }
                if (num[i] + num[p] + num[q] < target) p++;
                else if (num[i] + num[p] + num[q] > target) q--;
				else return num[i] + num[p] + num[q];
            }
        }
        return ans;
    }
};