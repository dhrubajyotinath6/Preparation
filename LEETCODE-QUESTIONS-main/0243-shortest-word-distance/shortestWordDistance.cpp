
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int i1 = -1, i2 = -1;
        int mini = INT_MAX;
        
        for(int i = 0; i < wordsDict.size(); i++){
           
            if(wordsDict[i] == word1){
                i1 = i;
            }else if(wordsDict[i] == word2){
                i2 = i;
            }
            
            if(i1 != -1 && i2 != -1){
                mini = min(mini, abs(i2-i1));
                if(mini == 1) return mini;
            }
        }
        return mini;
    }
};
