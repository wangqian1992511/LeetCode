class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        if (!n) return;
        sum.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (!i) return sum[j];
        return sum[j] - sum[i - 1];
    }
private:
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);