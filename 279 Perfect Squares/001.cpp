class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> s;
        if (!n) return 1;
        int lmt = sqrt(n + 0.1);
        queue<int> val, dist;
        val.push(0);
        dist.push(0);
        while (true) {
            int x = val.front();
            val.pop();
            int d = dist.front();
            dist.pop();
            int t = sqrt(n - x + 0.1);
            if (t * t + x == n)
                return d + 1;
            for (int i = 1; i <= t; i++)
                if (s.find(x + i * i) == s.end()) {
                    s.emplace(x + i * i);
                    val.push(x + i * i);
                    dist.push(d + 1);
                }
        }
    }
};