You are given a 0-indexed integer array nums and an integer k.

Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.

The set bits in an integer are the 1's present when it is written in binary.

For example, the binary representation of 21 is 10101, which has 3 set bits.
 

Example 1:

Input: nums = [5,10,1,5,2], k = 1
Output: 13
Explanation: The binary representation of the indices are: 
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002 
Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
Hence, the answer is nums[1] + nums[2] + nums[4] = 13.
Example 2:

Input: nums = [4,3,2,1], k = 2
Output: 1
Explanation: The binary representation of the indices are:
0 = 002
1 = 012
2 = 102
3 = 112
Only index 3 has k = 2 set bits in its binary representation.
Hence, the answer is nums[3] = 1.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
0 <= k <= 10


//https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/discuss/4063345/Hacker's-Delight

/*
class Solution {
    
public:    
    int bits(int i){
        int cnt = 0;
        
        while(i){
            cnt += i & 1;
            i >>= 1;
        }
        
        return cnt;
    }
    
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(k == bits(i)) sum += nums[i];
        }
        
       return sum;
        
    }
};

*/

//The getNextSamePopcount function (taken from the Hacker's Delight book) returns the next bigger number with the same number of bits set.






class Solution {
    
public:    
 int getNextSamePopcount(int a) {
    if (a == 0)
        return INT_MAX;
  int c = (a & -a), r = a + c;
  return ((((r ^ a) >> 2) / c) | r);
}
    
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for (int i = (1 << k) - 1; i < nums.size(); i = getNextSamePopcount(i))
            res += nums[i];
        return res;
    }
        
    
};

/*
k = 1,    start = 1 (1)
k = 2,    start = 3 (11)
k = 3,    start = 7 (111) -> 7 = 8 - 1 => (1 << k) - 1

*/

