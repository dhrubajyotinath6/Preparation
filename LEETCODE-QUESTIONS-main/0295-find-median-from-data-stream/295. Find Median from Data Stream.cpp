class MedianFinder {
    
    priority_queue<int> maxHeap; // containing first half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;// containing second half
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        // rebalance heaps
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        
        double ans;
        
        if(maxHeap.size() == minHeap.size()){
            ans = maxHeap.top()/2.0 + minHeap.top()/2.0;
            return ans;
        }
        else{
            ans = maxHeap.top()/1.0;
        }
        
      return ans;  
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
