You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element 
equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104


class Solution {
    
public:
    //0   0   4    9     4
    int findMaxSteal(vector<int> &wealth) {
        
    if (wealth.empty()) {
      return 0;
    }
        
    int n1 = 0, n2 = wealth[0], temp;
        
    for (int i = 1; i < wealth.size(); i++) {
      temp = max(n1 + wealth[i], n2);
      n1 = n2;
      n2 = temp;
    }
        
     return n2;
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        
       int maxi = nums[0];
       for(auto& num : nums){
           maxi = max(maxi, num);
       }
        
       vector<int> gold(maxi + 1);
       for(auto& num : nums){
           gold[num] += num;
       }
        
       return findMaxSteal(gold);
        
    }
};


