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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        vector<int> en;
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            bool haveFound = false;
            for (auto tm = en.begin(); tm != en.end(); tm++)
                if (it->start >= *tm) {
                    *tm = max(*tm, it->end);
                    haveFound = true;
                    break;
                }
            if (!haveFound)
                en.push_back(it->end);
        }
        return en.size();
    }
};