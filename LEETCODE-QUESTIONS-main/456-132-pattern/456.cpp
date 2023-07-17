Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


  //https://leetcode.com/problems/132-pattern/solution/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 3) return false;
        
        stack<int> st;
        vector<int>minArray(n);
        
        minArray[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            minArray[i] = min(minArray[i-1], nums[i]);
        }
        
        for(int j = n - 1; j > 0; j--){
            
            if(nums[j] <= minArray[j]) continue;
            
            while(st.empty() == false && st.top() <= minArray[j]) st.pop();
            
            if(st.empty() == false && st.top() < nums[j]) return true;
            
            st.push(nums[j]);
        }
        return false;
    }
};
