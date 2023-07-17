class Solution {
public:
    bool halvesAreAlike(string s) {
        
    //T E X T B O O K
    //0 1 2 3 4 5 6 7 
        
    // 7/2 = 3
        
        int n = s.size();
        int count = 0;
        
        string viowels = "aeiouAEIOU";
        
        for(int i = 0; i < n/2; i++){
            if(viowels.find(s[i]) != string::npos){
                count++;
            }
        }
        
        for(int i = n/2; i <n; i++){
            if(viowels.find(s[i]) != string::npos){
                count--;
            }
        }
        
        return count == 0;
    }
};