/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Comp {
    bool operator()(Interval &a, Interval &b) {
        if (a.start < b.start) return true;
        if (a.start > b.start) return false;
        if (a.end > b.end) return true;
        if (a.end < b.end) return false;
        return false;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        vector<Interval> ans;
        int n = intervals.size();
        int p = 0, q, e;
        while (p < n) {
            q = p + 1;
            e = intervals[p].end;
            while ((q < n) && (intervals[q].start <= e)) {
                if (intervals[q].end > e)
                    e = intervals[q].end;
                q++;
            }
            Interval tmp(intervals[p].start, e);
            ans.push_back(tmp);
            p = q;
        }
        return ans;
    }
};