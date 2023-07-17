
/*class Solution {
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
            }
        }
        return str;
    }
};
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string res;
        int open = 0;
        
        for(char c : s){
            if(c == '(' && open++ > 0) res += c;
            if(c == ')' && open-- > 1) res += c;
        }
        return res;
    }
};




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
