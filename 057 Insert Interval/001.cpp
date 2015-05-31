/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int i, n = intervals.size();
        for (i = 0; i < n; i++) 
            if (intervals[i].end < newInterval.start)
                ans.push_back(intervals[i]);
            else
                break;
        for (; i < n; i++)
            if ((intervals[i].end >= newInterval.start) && (intervals[i].start <= newInterval.end)) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
            else
                break;
        ans.push_back(newInterval);
        for (; i < n; i++)
            ans.push_back(intervals[i]);
        return ans;
    }
};
