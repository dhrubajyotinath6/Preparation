/*
 **********THIS LOGIG IS FOR DIFF >= k
it is not overwriting . just consider the case 2 2 0 8 9 9 2 and k = 3 .

i = 0 : 2 is not in the map then put it in the map

i = 1: 2 is in the map and now we check difference in the index . 
       Well it doesnot sastify conditions . Do nothing
       
i = 2 : 0 is not in the map . Put it in the map

Similarly
i = 3,4,5

Now,
i = 6 : 2 is already in the map . So check condition. Return true.

NOTE: in i = 1, when we encounter second 2 , we are not replacing it.


*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(map.find(nums[i]) != map.end()){
                
                int diff = i - map[nums[i]];
                if(diff <= k) return true;
            }
            
            //we need to overwrite the values since diff <= k , NOT diff >= K
                map[nums[i]] = i;
            
        }
        return false;
    }
};