class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue <int, vector<int>, greater<int>> minHeap;
        
        //if k = 2, i = 0,1
        for(int i = 0; i < nums.size(); i++){            
           minHeap.push(nums[i]); 
            
           if(minHeap.size() > k){
               minHeap.pop();
           }
        }
        
       return minHeap.top();
    }
};