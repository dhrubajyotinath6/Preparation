/*

You are given a string s consisting of lowercase English letters. 
A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"


*/

/*
Try to use something vector instead of stack so that we donot hv to reverse

*/

class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(auto ch : s){
            
            bool insert = true;
            
            if(!st.empty() && st.top() == ch){
                st.pop();
                insert = false;
            }
            
            if(insert) st.push(ch);
        }
        
        string ans;
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


//2nd approach

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/294893/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution

/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

/*
Input: s = "abbaca"
Output: "ca"

Input: s = "azxxzy"
Output: "ay"
*/
class Solution {
public:
     string removeDuplicates(string s) {
         
        int i = 0, n = s.length();
         
        for (int j = 0; j < n; ++j, ++i) {
            
            s[i] = s[j];
            
            if (i > 0 && s[i - 1] == s[i]){ // count = 2
                i -= 2;
                // cout << i << endl;
            }                
            
        }
         
        return s.substr(0, i);
    }
};

/*
Your input
"leelcode"

stdout
0
-1

Output
"code"

Expected
"code"


*/