class Solution {
public:
    bool isHappy(int n) {
        unordered_map <int, int> hash;
        int t = 0;
        while (n != 1) {
            if (hash.find(n) != hash.end())
                return false;
            hash[n] = t++;
            n = generate(n);
        }
        return true;
    }
private:
    int generate(int n) {
        int ans = 0;
        while (n) {
            int t = n % 10;
            ans += (t * t);
            n /= 10;
        }
        return ans;
    }
};