class KthLargest {
    
      struct numCompare {
        bool operator()(const int &x, const int &y) { return x > y; }
      };
    
      priority_queue<int, vector<int>, numCompare> minHeap;
      int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;
        
        for(auto &num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        
        minHeap.push(val);

        // if heap has more than 'k' numbers, remove one number
        if ((int)minHeap.size() > k) {
          minHeap.pop();
        }

        // return the 'Kth largest number
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */