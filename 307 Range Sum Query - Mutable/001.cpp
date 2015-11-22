class NumArray {
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        data = new int [n];
        c = new int [n + 1];
        fill(data, data + n, 0);
        fill(c, c + n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int delta = val - data[i];
        data[i] = val;
        i++;
        while (i <= n) {
            c[i] += delta;
            i += lowbit(i);
        }
    }
    
    int sumRange(int i, int j) {
        j++;
        int sumI = 0, sumJ = 0;
        while (i) {
            sumI += c[i];
            i -= lowbit(i);
        }
        while (j) {
            sumJ += c[j];
            j -= lowbit(j);
        }
        return sumJ - sumI;
    }
private:
    int *c, n, *data;
    int lowbit(int x) {
        return x & -x;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);