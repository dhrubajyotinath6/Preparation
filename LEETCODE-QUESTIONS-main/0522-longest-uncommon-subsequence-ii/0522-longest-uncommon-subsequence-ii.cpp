//https://leetcode.com/problems/longest-uncommon-subsequence-ii/solution/


class Solution {
    
public:
    bool isSubsequence(string x, string y){
        
        int j = 0;
        for(int i = 0; i < x.size() && j < y.size(); i++){
            if(x[i] == y[j]) j++;
        }
        
        return j == y.size();
    }
    
public:
    static bool cmp(string &s1, string &s2) {
       return s1.length() > s2.length();
    }
    
    
public:    
    int findLUSlength(vector<string>& strs) {
        
        //sort the string based on length
         sort(begin(strs), end(strs), [](const auto &a, const auto &b){ return a.size() > b.size(); });
        
        
        for(auto& str : strs){
            cout << str << endl;
        }
        
        for(int i = 0; i < strs.size(); i++){
            bool canAnswer = true;
            for(int j = 0; j < strs.size(); j++){
                
                if(i == j) continue;
               //we are check whether i is subsequence of all j 
                if(isSubsequence(strs[j], strs[i])){
                    canAnswer = false;
                    break;
                }
            }
            
            if(canAnswer){
                return strs[i].size();
            }
        }
        
        return -1;
    }
};