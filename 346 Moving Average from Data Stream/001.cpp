class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        avg = 0;
    }

    double next(int val) {
        q.push(val);
        if (q.size() <= size) {
            avg = (avg * (q.size() - 1) + val) / q.size();
            return avg;
        }
        avg += (val - q.front()) / size;
        q.pop();
        return avg;
    }

private:
    queue<int> q;
    int size;
    double avg;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
