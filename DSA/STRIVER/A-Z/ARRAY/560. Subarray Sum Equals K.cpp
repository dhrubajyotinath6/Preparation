Given an array of integers nums and an integer k, return the total number of 
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0;
        
        for(int start = 0; start < nums.size(); start++){
            int sum = 0;
            for(int end = start; end < nums.size(); end++){
                sum += nums[end];
                
                if(sum == k) ans++;
            }
        }
        
        return ans;
    }
};

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0, sum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
 
/*
suppose k = 5

if sum = 3

if sum = 9, we need to check whether 4 is there or not

if sum = 5, we need to check whether 0 is there or not
*/
            if(map.find(sum - k) != map.end()){
                ans += map[sum - k];
            }
            
            map[sum]++;
        }

        return ans;
    }
};