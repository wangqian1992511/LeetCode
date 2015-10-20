class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty())
                maxHeap.push(num);
            else if (num > maxHeap.top())
                minHeap.push(num);
            else 
                maxHeap.push(num);
        }
        else if (maxHeap.size() > minHeap.size()) {
            if (num > maxHeap.top())
                minHeap.push(num);
            else {
                maxHeap.push(num);
                int x = maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
            }
        }
        else {
            if (num < minHeap.top())
                maxHeap.push(num);
            else {
                minHeap.push(num);
                int x = minHeap.top();
                minHeap.pop();
                maxHeap.push(x);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) 
            return (maxHeap.top() + minHeap.top()) * 0.5;
        else if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else 
            return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
