
/*
a     b       c       d

when i = 3,
    s = d
    
when i = 2,
    s = c + 2*d = d + (c + d)


*/

//greedy
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(), satisfaction.end());
        
        int maxSatisfaction = 0;
        int suffixSum = 0;
        
        for(int i = satisfaction.size()-1; i >= 0; i--){
            
            if((suffixSum + satisfaction[i]) < 0) continue;
            else{
                suffixSum += satisfaction[i];
                maxSatisfaction += suffixSum;
            }
        }
        
        return maxSatisfaction;
    }
};