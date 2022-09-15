/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

*/


//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/383670/JavaC%2B%2BPython-Tenet-O(N)-Solution

/*
    string reverseParentheses(string s) {
        vector<int> opened;
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                opened.push_back(res.length());
            else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                reverse(res.begin() + j, res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }


*/
// i = index, d = direction
class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.length();
        
        vector<int> opened, pair(n);
        
        for (int i = 0; i < n; ++i) {
            
            if (s[i] == '(')
                opened.push_back(i);
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        string res;
        
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;
            else
                res += s[i];
        }
        
        return res;
    }
};


/*
i = index, d = direction

The second solution can be broken down into 3 steps:

track matching braces in map

use matching braces as wormholes, i.e., jump to the matching brace using the map

change direction every time we hit a brace

Ex: lee(ct)ode
When i is at index 3, 'res' is ['l', 'e', 'e']. Using the map, we jump to 6 and change direction. 
Add 't' and 'c' to 'res'. Now i is back at 3 again. We again jump to 6 and change direction 
one more time. Now add rest of the characters to 'res'.

*/