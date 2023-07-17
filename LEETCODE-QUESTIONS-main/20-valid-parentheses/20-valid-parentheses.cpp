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