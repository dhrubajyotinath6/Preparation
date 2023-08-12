/*
https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

The beauty of a string is the difference in frequencies between the most frequent 
and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], 
each with beauty equal to 1.


Example 2:

Input: s = "aabcbaa"
Output: 17
*/

// think of kadane 

class Solution {
    
public:
    int beauty(vector<int> &freq){
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) continue;
            
            mini = min(freq[i], mini);
            maxi = max(freq[i], maxi);
        }
       
       return maxi - mini;
        
    }
public:
    int beautySum(string s) {
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            
           vector<int> freq(26,0);
            
           for(int j = i; j < s.length(); j++){
               freq[s[j] - 'a']++;
               ans += beauty(freq);
           }
        }
    return ans;
    }

};