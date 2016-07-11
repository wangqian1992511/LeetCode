class Solution {
public:
    int superPow(int a, vector<int>& b) {
        c = 1337;
        return superExp(a % c, b);
    }
private:
    int c;
    int mul(int a, int b) {
       return a * b % c;
    }
    int exp(int a, int b) {
        if (!b)
            return 1;
        if (b == 1)
            return a;
        int t = exp(a, b >> 1);
        t = mul(t, t);
        if (b & 1)
            return mul(t, a);
        return t;
    }
    int superExp(int a, vector<int>& b) {
        if (b.size() == 1)
            return exp(a, b[0]);
        int x = b.back();
        b.pop_back();
        return mul(exp(superExp(a, b), 10), exp(a, x));
    }
};
