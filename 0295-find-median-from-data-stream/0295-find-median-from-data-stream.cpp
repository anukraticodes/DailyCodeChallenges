class MedianFinder {
public:
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
  
        if(pq.empty() || num<pq.top()) {pq.push(num);}
        else pq2.push(num);

        while(pq.size()>pq2.size()+1){
            int x=pq.top();
            pq.pop();
            pq2.push(x);
        }
        while(pq2.size()>pq.size()+1){
            int x=pq2.top();
            pq2.pop();
            pq.push(x);
        }
    }
    
    double findMedian() {
        if(pq.size()>pq2.size()){
            return pq.top();
        }
        if (pq2.size() > pq.size()) {
        return pq2.top();
    }
        
        else{
            return (double)(pq.top()+pq2.top())/2.0;
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */