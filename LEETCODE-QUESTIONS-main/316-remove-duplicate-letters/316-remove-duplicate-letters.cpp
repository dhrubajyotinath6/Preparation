//https://leetcode.com/problems/remove-duplicate-letters/solution/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> st;
        set<char> seen; 
        unordered_map<char, int> lastOccurence; 
        
        for(int i = 0; i < s.length(); i++) lastOccurence[s[i]] = i;
        
        for(int i = 0; i < s.length(); i++){
            
            char c = s[i];
            
            if(seen.find(c) == seen.end()){
                
                while(st.empty() == false && c < st.top() && lastOccurence[st.top()] > i){
                    char ch = st.top();
                    st.pop();
                    seen.erase(ch);
                }
                
                seen.insert(c);
                st.push(c);
            }
        }
        
        string ans = "";
        
        while (st.size() > 0){            
             ans = st.top() + ans; 
             st.pop();
        }
        
        // reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};