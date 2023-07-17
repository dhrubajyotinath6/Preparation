/*
https://leetcode.com/problems/buildings-with-an-ocean-view/solution/

Monotonic Stack -> tc = o(n), sc = o(n)

below approach  -> tc= o(n), sc= o(1)
*/
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        int n = heights.size();
        int maxHeight = -1;
        
        vector<int> ans;
        
        for(int i = n-1; i >= 0; i--){
            
            if(maxHeight < heights[i]){
                ans.push_back(i);
                
                maxHeight = heights[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};