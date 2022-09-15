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
