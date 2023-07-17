class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int loc = -1;
        int capitalCount = 0;
        
        for(int i = 0; i < word.length(); i++){
            
            if(word[i] >= 'A' && word[i] <= 'Z'){
                capitalCount++;
                loc = i;
            }
        }
        
        // all capital || no capital || firstLetterCap
        if(capitalCount == word.length() || capitalCount == 0 || (capitalCount == 1 && loc == 0)){
            return true;
        }
        return false;
    }
};