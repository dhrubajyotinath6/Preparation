/*
https://www.youtube.com/watch?v=CZQGRp93K4k


https://github.com/dhrubajyotinath6/Preparation/tree/master/DSA/LEETCODE%20TOP%20INTERVIEW%20QUESTIONS/SLIDING%20WINDOW%20MAXIMUM
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};