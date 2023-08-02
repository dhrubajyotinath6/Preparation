/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, 
where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it 
into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".



Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".




Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

*/


class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<int> st;
        string str = "";
        
        for(int i = 0; i < s.size(); i++){
            
            char ch = s[i];
            
            if(ch == '('){
                
                if(st.size() > 0)   str+=ch;
                st.push(ch);
            }
            else{
                st.pop();
                if(st.size() > 0)   str+=ch;
                // str += ch;
            }
        }
        return str;
    }
};

/*
    if(st.size() > 0)   str+=ch;
    str += ch;


Your input
"(()())(())"

Output
"()())())"

Expected
"()()()"

*/

OPTIMIZED SOLUTION ; TC -> O(N),  SC -> O(1)
 
 class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int bal = 0;
        string ans = "";
        
        for(auto& ch : s){
            
            if(ch == '('){
                
                if(bal != 0){
                    ans += ch;
                }
                
            }else{ // ch == ')'
                
                if(bal > 1){
                    ans += ch;
                }
            }
            
            bal += (ch == '(') ? 1:-1;
            
            }
        
        
        return ans;
    }
  
 };
  //https://leetcode.com/problems/remove-outermost-parentheses/discuss/270022/JavaC%2B%2BPython-Count-Opened-Parenthesis
class Solution {
public:
    string removeOuterParentheses(string s) {
       
        int opened = 0;
        string res;
        
        for(auto &c : s){
            if(c == '(' && opened++ > 0) res += c;
            if(c == ')' && --opened > 0) res += c;
        }
        
        return res;
    }
};


