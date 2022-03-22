class MedianFinder {
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
public:
    MedianFinder() {}
    
    void balance() {
        while(q1.size() < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        }
        
        if((q1.size() - q2.size()) > 1) {
            q2.push(q1.top());
            q1.pop();
        }
        
    }
    
    void addNum(int num) {
        if(q1.empty() || num < q1.top()) q1.push(num);
        else q2.push(num);
        
        balance();
    }
    
    double findMedian() {
        if(q1.size() > q2.size()) return q1.top();
        else return ((float)(q1.top() + q2.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */