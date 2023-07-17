// t.length == s.length

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        
        unordered_map<char,char> mppS_T;
        unordered_map<char,char> mppT_S;
        
        for(int i = 0; i < n; i++){
            
            char chS = s[i], chT = t[i];
            
            if(mppS_T.find(chS) == mppS_T.end() && mppT_S.find(chT) == mppT_S.end()){
                
                mppS_T[chS] =  chT;
                mppT_S[chT] =  chS;
            }
            
            else if(mppS_T.find(chS) != mppS_T.end() || mppT_S.find(chT) != mppT_S.end()){
                
                if(mppS_T[chS] != chT) return false;
                if(mppT_S[chT] != chS) return false;
            }            
            
        }
        
        return true;
    }
};

/*
Input
"badc"
"baba"

Output
true

Expected
false

*/