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
        vector<Interval>::iterator it = intervals.begin();

        while (it != intervals.end()) {
            if (it->end < newInterval.start)
                ans.push_back(*it);
            else
                break;
            it++;
        }
        while (it != intervals.end()) {
            if ((it->end >= newInterval.start) && (it->start <= newInterval.end)) {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
            else
                break;
            it++;
        }
        ans.push_back(newInterval);
        while (it != intervals.end()) {
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};
