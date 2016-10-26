class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxRootSmallHeap.empty()) {
            maxRootSmallHeap.push(num);
        }else if (num < maxRootSmallHeap.top()) {
            maxRootSmallHeap.push(num);
            if (maxRootSmallHeap.size() == minRootLargeHeap.size() + 2) {
                int x = maxRootSmallHeap.top();
                maxRootSmallHeap.pop();
                minRootLargeHeap.push(x);
            }
        } else {
            minRootLargeHeap.push(num);
            if (minRootLargeHeap.size() == maxRootSmallHeap.size() + 1) {
                int x = minRootLargeHeap.top();
                minRootLargeHeap.pop();
                maxRootSmallHeap.push(x);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minRootLargeHeap.size() == maxRootSmallHeap.size()) {
            return minRootLargeHeap.top() + (maxRootSmallHeap.top() - minRootLargeHeap.top()) * 0.5;
        } else {
            return maxRootSmallHeap.top();
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>> minRootLargeHeap;
    priority_queue<int, vector<int>, less<int>> maxRootSmallHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
