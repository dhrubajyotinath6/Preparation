You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109


/*
https://leetcode.com/problems/count-number-of-bad-pairs/discuss/2388183/n*(n-1)2-Valid-oror-(C%2B%2BJava)

Trick to this problem:
Total= Valid + Invalid
Invalid = Total- Valid

The real Equation: ( j - i ) != ( A[j] - A[i] )
The simple and more intuitive form of above equation: ( j - A[j] ) != ( i - A[i] )


invalid :: ( j - A[j] ) != ( i - A[i] )
valid   :: ( j - A[j] )  = ( i - A[i] )  -- count this 

*/


/*
O(n^2)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       
        long long cnt = 0;
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(j - i != nums[j] - nums[i]) cnt++;
            }
        }
        
        return cnt;
    }
};
*/


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       
        long long cnt = 0;
        int n = nums.size();
        
        unordered_map<int, long long> mpp;
        
        for(int i = 0; i < n; i++){
            
            int diff = i - nums[i];
            cnt += mpp[diff];
            
            mpp[diff]++;
            
        }
        
        return  1L*n*(n-1)/2 - cnt;;
    }
};