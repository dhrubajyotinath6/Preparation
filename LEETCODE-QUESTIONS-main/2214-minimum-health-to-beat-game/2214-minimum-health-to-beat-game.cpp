class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        int maxi = 0;
        long health = 1; 
        
        for(int i=0; i<damage.size();i++){
            health += damage[i];
            maxi = max(maxi,damage[i]);
        }
        
        health -= min(maxi,armor);
        return health;
    }
};