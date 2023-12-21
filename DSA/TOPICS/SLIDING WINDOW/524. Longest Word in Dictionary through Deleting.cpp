Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
 

Constraints:

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.

class Solution {
    
public:
    bool isPossible(string str, string s){
        
        int i = 0, j = 0;
        
        while(i < s.size()){
            if(s[i] == str[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j == str.size();
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string ans = "";
        
        for(auto& str : dictionary){
            
            if(isPossible(str, s)){
                if(ans.size() == 0 || str.size() > ans.size()) ans = str;
                else if(ans.size() == str.size()) ans = min(ans,str); 
            }
            
        }
        
        return ans;
    }
};