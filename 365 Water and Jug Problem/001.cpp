class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return !z || ((x + y >= z) && !(z % gcd(x,y)));
    }
private:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
};
