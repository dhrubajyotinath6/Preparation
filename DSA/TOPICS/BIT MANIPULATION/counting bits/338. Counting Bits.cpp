/*
https://leetcode.com/problems/counting-bits/

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

*/

class Solution {
    
    int noOf1s(int n){
        
        int count = 0;
        
        while(n > 0){
            n = n&(n-1);
            count++;
        }
        
        return count;
    }
    
    
 //OPTIMAL SOLUTION
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> res(n+1);
        res[0] = 0;
        
        for(int i = 1; i <= n; i++){
            res[i] = res[i/2] + i%2;
        }
        
        return res;
    }
};
    
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        
        for(int i = 0; i <= n; i++){
            
            ans.push_back(noOf1s(i));
        }
        
        return ans;
    }
};
