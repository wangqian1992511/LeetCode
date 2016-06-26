/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        toClear = false;
    }

    void addNum(int val) {
        if (num.count(val))
            return;
        num.insert(val);
        toClear = true;

        if (right.count(val - 1))
            right.erase(val - 1);
        else
            left.insert(val);

        if (left.count(val + 1))
            left.erase(val + 1);
        else
            right.insert(val);
    }

    vector<Interval> getIntervals() {
        if (!toClear) return ans;
        ans.clear();
        auto it = left.begin();
        auto e = left.end();
        auto jt = right.begin();
        while (it != e) {
            ans.push_back(Interval(*it, *jt));
            it++;
            jt++;
        }
        return ans;
    }
private:
    set<int> left, right;
    unordered_set<int> num;
    vector<Interval> ans;
    bool toClear;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
