You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, 
  if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
Example 2:

Input: order = "cbafg", s = "abcd"
Output: "cbad"


  //https://leetcode.com/problems/custom-sort-string/solution/
class Solution {
public:
    string customSortString(string order, string s) {
        
        int count[26] = {0};
        
        for(auto c : s){
            count[c - 'a']++;
        }
        
        string ans = "";
        
        // Write all characters that occur in s, in the order of order.
        for(auto c : order){
            
            for(int i = 0; i < count[c - 'a']; i++){
                ans += c;
            }
            count[c - 'a'] = 0;
        }
        
        // Write all remaining characters that don't occur in order.
        // That information is specified by 'count'.
        for(char c = 'a'; c <= 'z'; c++){
            for(int i = 0; i < count[c - 'a']; i++)
                ans += c;
        }
        
        return ans;
    }
};
