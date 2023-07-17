/*
using stack

tc - O(n)
sc - O(n)
*/

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int maxLen = 0;
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                
                if(st.empty()){
                    st.push(i);
                }else{
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        
        return maxLen;
    }
};

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left = 0, right = 0, maxLength = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') left++;
            else right++;
            
            if(left == right) maxLength = max(maxLength, 2 * right);
            else if(right >= left) left = right = 0;
        }
        
        left = right = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(') left++;
            else right++;
            
            if(left == right) maxLength = max(maxLength, 2*left);
            else if(left >= right) left = right = 0;
        }
        
    
        return maxLength;
    }
};