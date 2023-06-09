Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 


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


https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/  -- same question
Given a string s, return the lexicographically smallest subsequence of s 
that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
