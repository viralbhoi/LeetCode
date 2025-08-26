class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    double median;
    MedianFinder() { median = 0.0; }

    void addNum(int num) {
        if (num > median) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }

        if (minHeap.size() + 2 == maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            median = (minHeap.top() + maxHeap.top()) / 2.0;
        } else if (minHeap.size() == maxHeap.size() + 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();

            median = (minHeap.top() + maxHeap.top()) / 2.0;
        } else {
            if (maxHeap.size() > minHeap.size()) {
                median = maxHeap.top();
            } else {
                median = minHeap.top();
            }
        }
    }

    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */