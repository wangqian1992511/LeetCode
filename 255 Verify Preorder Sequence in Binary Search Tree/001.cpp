class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verify(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
private:
    bool verify(vector<int>& preorder, int st, int en, int lb, int ub) {
        if (st > en) return true;
        if (!isRange(preorder[st], lb, ub)) return false;
        
        int l = st + 1, r = en, m;
        int key = preorder[st];
        while (l <= r) {
            m = (l + r) >> 1;
            if (!isRange(preorder[m], lb, ub)) return false;
            if (preorder[m] < key) 
                l = m + 1;
            else 
                r = m - 1;
        }
        return verify(preorder, st + 1, r, lb, key) && verify(preorder, l, en, key, ub);
    }
    bool isRange(int x, int lb, int ub) {
        return (x > lb) && (x < ub);
    }
};