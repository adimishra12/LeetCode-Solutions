class MedianFinder {
public:
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        pq2.push(pq.top());
        pq.pop();
        if(pq2.size() > pq.size())
        {
            pq.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq.size() > pq2.size())
            return pq.top();
        else
            return (pq.top() + pq2.top()) / 2.0;    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */