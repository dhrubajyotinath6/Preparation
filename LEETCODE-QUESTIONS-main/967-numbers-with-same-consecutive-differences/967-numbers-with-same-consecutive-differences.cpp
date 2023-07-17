/*

Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. 
You may return the answer in any order.

Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

 

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


/*
x = 83
y = 3 
k = 3

ans = 830

----

x = 80
y= 0
k = 0

ans = 800 + 0 = 800   thats why k > 0


*/
