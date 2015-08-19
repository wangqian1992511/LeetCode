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
    bool operator () (Interval &a, Interval &b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        int en = INT_MIN;
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (it->start < en) return false;
            en = max(en, it->end);
        }
        return true;
    }
};