//https://leetcode.com/problems/ransom-note/solution/ -check all approaches

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // Check for obvious fail case.
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        unordered_map<char,int> map;
        
        for(auto &ch : magazine){
            map[ch]++;
        }
        
        for(auto &ch : ransomNote){
            
            if(map[ch] == 0) return false;
                
            else{
                map[ch]--;
            }
        }
        return true;
    }
};
