class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        set<char> hashSet;
        
        for(auto ch : allowed){
            hashSet.insert(ch);
        }
        
        int ans = 0;
        
        for(auto word : words){
            
            bool isConsistent = true;
            
            for(auto ch : word){
                
                if(!hashSet.count(ch)){
                    isConsistent = false;
                }
            }
            
            if(isConsistent) ans++;
        }
        
        return ans;
    }
};