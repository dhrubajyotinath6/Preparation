The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        set<string> st;
        vector<string> ans;
        
        set<string> st2;
        
        int i = 0; 
        
        for(int i = 0; i + 9 <= s.size(); i++){
            
            string subStr = s.substr(i,10);
            
            //already the string is there and we hv not included it in the ans
            if(st.find(subStr) != st.end() && st2.find(subStr) == st2.end()){
                st2.insert(subStr);
                ans.push_back(subStr);
            }else{
                st.insert(subStr);
            }
        }
        
        return ans;
    }
};