/*
https://leetcode.com/problems/score-of-parentheses/solution/    --VERY IMP

https://leetcode.com/problems/score-of-parentheses/solution/314388

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
*/


/*
Let me explain the third solution as best as I can since it's really elegant.

The key idea is that:

the balance tells you what "depth" you are at since with each '(' we are increasing the depth by 1 
(kind of similar to the concept in Solution 2).

the "cores" () are the only structure that provides value, the outer parentheses just 
add some multiplier to the cores. So we only need to be concerned with those.

With those 2 ideas in mind, we are able to calculate how much the "core" is worth directly 
without having to calculate substructures recursively and then apply multipliers.

E.g. For the example of ( ( ) ( ( ) ) ), with the stack method, 
we are calculating the inner structure ( ) ( ( ) ) first and 
then multiplying the score by 2. 

With the 3rd method, by knowing the depth of the core,
 we are actually performing this calculation ( ( ) ) + ( ( ( ) ) ).

Hope this helps :)

*/
/*
class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '(') st.push(-1);
            
            else{
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }else{
                    int val = 0;
                    while(st.top() != - 1){                       
                        val += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*val);
                }
                
            }                
        }
        int val = 0;
        while(st.size() > 0){
            val += st.top();
            st.pop();
        }
        return val;
    }
};
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        
         int ans = 0, bal = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                if (s[i-1] == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
};
