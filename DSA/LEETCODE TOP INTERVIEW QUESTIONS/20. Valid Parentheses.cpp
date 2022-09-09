/*
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/

class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char,char> mpp;
        mpp[')'] = '(';
        mpp['}'] = '{';
        mpp[']'] = '[';
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            
            char ch = s[i];
            
            // If the current character is a closing bracket.
            if(mpp.find(ch) != mpp.end()){
                
                char topEle;
                
                if(!st.empty()){
                    topEle = st.top();
                    st.pop();
                }
                else{
                    topEle = '#';
                }
                
                // If the mapping for this bracket doesn't match the stack's top element, return false
                
                if(topEle != mpp[ch]) return false;
                
            }
            // If the current character is not a closing bracket.
            else{
                 // If it was an opening bracket, push to the stack.
                st.push(ch);                
            }
        }
        
        // If the stack still contains elements, then it is an invalid expression.
        return st.empty();
    }
};