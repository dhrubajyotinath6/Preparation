class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int tot = 0;
        
        for(int i = 0; i < timeSeries.size() - 1; i++){
            
            tot += min(timeSeries[i+1] - timeSeries[i], duration);
        }
        
        return tot + duration;
    }
};