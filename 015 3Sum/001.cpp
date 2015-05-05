class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        for (int i = 0; i <= n-3; i++) {
            if ((i != 0) && (num[i] == num[i-1]))
                continue;
            int q = n - 1;
            int p = i + 1;
            while (p < q) {
                if (num[i] + num[p] + num[q] == 0) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[p]);
                    tmp.push_back(num[q]);
                    ans.push_back(tmp);
                    p++;
                    q--;
                    while ((p < q) && (num[p] == num[p-1])) p++;
                    while ((p < q) && (num[q] == num[q+1])) q--;
                }
                else if (num[i] + num[p] + num[q] < 0)
                    p++;
                else
                    q--;
            }
        }
        return ans;
    }
};