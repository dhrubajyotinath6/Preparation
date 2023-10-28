We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

 

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
Example 3:

Input: s1 = "a", s2 = "a"
Output: true

class Solution {
public:    
     unordered_map<string,bool> dp;
    
     bool isScramble(string s1, string s2) {
         
        if(s1.size()!=s2.size()){
            return false;
        }
         
        if(s1 == s2){
            return true;
        }
         
        if(dp.find(s1+s2) != dp.end()){
            return dp[s1+s2];
        }
                 
        vector<int> freq(26,0);
         
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
         
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return dp[s1+s2]=false;
            }
        }
         
         int n = s1.size();
         
         for (int i = 1; i <= n - 1; i++){
             
           // g r | e a t ,  r g | e a t
           if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
               dp[s1 + s2] = true;
               return true;
           }
           
           // g r | e a t  ,  e a t | g r
           if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))){
               dp[s1 + s2] = true;
               return true;
           }
           
    }
     dp[s1 + s2] = false;
    return false;
    }
    
}; 
