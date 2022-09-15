/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/solution/

*/

/*class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            
            if(ch == '('){
                st.push(ch);
            }
            
            else{
                if(st.size() > 0 && st.top() == '('){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
       return st.size(); 
    }
};
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int bal = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            char ch = s[i];
            
            bal += ch == '(' ? 1 : -1;
            
            if(bal == -1){
                ans++;
                bal++;
            }
        }
        return ans + bal;   
            
    }
};