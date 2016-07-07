class Solution {
public:
    int superPow(int a, vector<int>& b) {
        c = 1337;
        a %= c;

        int ex[10];
        ex[0] = 1;
        for (int i = 1; i < 10; i++)
            ex[i] = mul(ex[i - 1], a);

        int ans = 1;
        for (auto it = b.rbegin(); it != b.rend(); it++) {
            ans = mul(ans, ex[*it]);
            for (int i = 0; i < 10; i++)
                ex[i] = update(ex[i]);
        }

        return ans;
    }
private:
    int c;
    int mul(int a, int b) {
       return a * b % c;
    }
    int update(int x) {
        int t = x;
        int t2 = mul(t, t);
        t = mul(t2, t2);
        t = mul(t, t);
        return mul(t, t2);
    }
};
