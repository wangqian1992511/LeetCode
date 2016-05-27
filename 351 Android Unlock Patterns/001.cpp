class Solution {
public:
    int numberOfPatterns(int m, int n) {
        lb = m;
        ub = n;
        ans = (m == 1) ? 9 : 0;
        isFour = true;
        state = 1020;
        pre = 2;
        dfs(2);
        state = 1018;
        pre = 4;
        dfs(2);
        isFour = false;
        state = 990;
        pre = 32;
        dfs(2);
        return ans;
    }
private:
    int state, pre, lb, ub, ans;
    bool isFour;
    int lowbit(int x) {
        return x & -x;
    }
    void dfs(int dep) {
        if (dep > ub)
            return;
        int tState = state;
        while (tState) {
            int x = lowbit(tState);
            tState -= x;
            state -= x;
            if (isValid(x)) {
                if (dep >= lb)
                    ans = ans + (isFour ? 4 : 1);
                int tPre = pre;
                pre = x;
                dfs(dep + 1);
                pre = tPre;
            }
            state += x;
        }
    }
    bool isValid(int x) {
        if ((x == (pre << 2)) && (state & (pre << 1)))
            return (pre != 2) && (pre != 16) && (pre != 128);
        if ((pre == (x << 2)) && (state & (x << 1)))
            return (x != 2) && (x != 16) && (x != 128);
        if ((x == (pre << 6)) && (state & (pre << 3)))
            return (pre != 2) && (pre != 4) && (pre != 8);
        if ((pre == (x << 6)) && (state & (x << 3)))
            return (x != 2) && (x != 4) && (x != 8);
        if ((x == (pre << 4)) && (state & (pre << 2)))
            return (pre != 8);
        if ((x == (pre << 8)) && (state & (pre << 4)))
            return (pre != 2);
        if ((pre == (x << 4)) && (state & (x << 2)))
            return (x != 8);
        if ((pre == (x << 8)) && (state & (x << 4)))
            return (x != 2);
        return true;
    }
};
