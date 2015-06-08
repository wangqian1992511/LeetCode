/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> cnt;
            int sum = 0, tmp = 0;
            for (int j = 0; j < n; j++)
                if (isDiff(points[i], points[j])) {
                    double k;
                    if (points[i].x != points[j].x)
                        k = double(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    else
                        k = 1e100;
                    if (cnt.find(k) != cnt.end())
                        cnt[k]++;
                    else
                        cnt[k] = 1;
                    tmp = max(tmp, cnt[k]);
                }
                else
                    sum++;
            ans = max(ans, sum + tmp);
        }
        return ans;
    }
private:
    inline bool isDiff(Point a, Point b) {
        return (a.x != b.x) || (a.y != b.y);
    }
};