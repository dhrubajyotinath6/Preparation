You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, 
and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
  
  
  
  class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        
        
        string temp;
        
        for(int i = 0; i < nums.size(); i++){
            
            int start = nums[i];
            
            // 0 1 2 | 4 5 7
            while(i + 1 < nums.size() && nums[i]+1 == nums[i+1]){
                i++;
            }
            //i = 2
            if(start != nums[i]){
                temp += to_string(start);
                temp += "->";
                temp += to_string(nums[i]);
                
                ans.push_back(temp);
                temp.clear();
            }
            else{
                ans.push_back(to_string(nums[i]));
            }
            
        }
        return ans;
    }
};
