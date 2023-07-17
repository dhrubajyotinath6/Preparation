/*
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/solution/

*/
class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> frequency(26,0);
        
        for(char c : s){
            frequency[c - 'a']++;
        }
        
        sort(frequency.begin(), frequency.end(), greater<int>());
        
        int deleteCount = 0;
        
        int maxFreqAllowed = s.size();
        
        for(int i = 0; i < 26 && frequency[i] > 0; i++){
            
            if(frequency[i] > maxFreqAllowed){
                deleteCount += frequency[i] - maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            maxFreqAllowed = max(0, frequency[i] - 1);
        }
        return deleteCount;
    }
};