/*
Return all non-negative integers of length n such that the absolute difference between 
every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one 
leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]


*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> curr1 = {1,2,3,4,5,6,7,8,9};
        
        for(int i = 2; i <= n; i++){
            
            vector<int> curr2;
            
            for(int x : curr1){          
            
            int y = x % 10;
            
            if(y + k < 10) curr2.push_back(x*10 + (y + k));
            if(y - k >= 0 && k > 0) curr2.push_back(x*10 + (y-k));
        }
        
            curr1 = curr2;
        }
        
        return curr1;
        
    }
};