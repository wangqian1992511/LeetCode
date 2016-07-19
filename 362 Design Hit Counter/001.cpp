class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        current = -1;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (timestamp != current){
            current = timestamp;
            t.push(timestamp);
            c.push(1);
        }
        else {
            c.back()++;
        }
        cnt++;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        current = timestamp;
        while (!t.empty() && (t.front() + 300 <= timestamp)) {
            t.pop();
            cnt -= c.front();
            c.pop();
        }
        return cnt;
    }
private:
    queue<int> t, c;
    int current, cnt;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
