class Solution {
public:
    int numSquares(int n) {
        bool *vis = new bool [n + 1];
        if (!n) return 1;
        fill(vis, vis + n + 1, false);
        queue<int> val, dist;
        val.push(0);
        dist.push(0);
        vis[0] = true;
        while (true) {
            int x = val.front();
            val.pop();
            int d = dist.front();
            dist.pop();
            int t = sqrt(n - x);
            if (t * t + x == n)
                return d + 1;
            for (int i = 1; i <= t; i++)
                if (!vis[x + i * i]) {
                    vis[x + i * i] = true;
                    val.push(x + i * i);
                    dist.push(d + 1);
                }
        }
    }
};