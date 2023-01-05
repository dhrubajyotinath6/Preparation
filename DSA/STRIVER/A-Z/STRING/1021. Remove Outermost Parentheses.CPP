/*
https://leetcode.com/problems/remove-outermost-parentheses/

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

// OPTIMAL APPROACH
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

