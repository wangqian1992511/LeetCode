/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct CompT {
    bool operator()(Interval &a, Interval &b) {
        return (a.start < b.start) || ((a.start == b.start) && (a.end > b.end));
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), CompT());
        vector<Interval> ans;
        Interval current(INT_MIN, INT_MIN);
        for (auto it: intervals) {
            if (current. end >= it.start)
                current.end = max(current.end, it.end);
            else {
                ans.push_back(current);
                current = it;
            }
        }
        ans.push_back(current);
        ans.erase(ans.begin());
        return ans;
    }
};
