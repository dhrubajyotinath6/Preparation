class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        
        int sum = 0;
        map[0] = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum += nums[i];
            
            if(!map.count(sum % k)){
                map[sum % k] = i + 1;
            }else if(map[sum % k] < i){
                return true;
            }           
            
        }
        
        return false;
    }
};

/*
This helped me visualize the ans. In the example:
[23,2,6,4,7] k =12

(23)%12 = 11
(23+2)%12=1
(23+2+6)%12 = 7
(23+2+6+4)%12=11 -> seen before, so return true because:

(23+2+6+4) - (23) = 12 -> 12 % 12 = 0

*/

/* dry run [5, 2, 0, 4, 7], k = 6
hashmap (0,0)

i = 0, sum = 5 => 5
hashmap (0,0), (5,1)

i = 1, sum = 5 + 2 => 1
hashmap (0,0), (5,1) (1,2)

i = 2, sum = 1 + 0 => 1
find hashmap[1] = 2
i = 2 == 2, continue (len == 1)

i = 3, sum = 1 + 4 => 5
find hashmap[5] = 1
i = 3 > 1 => return true // index 1 ~ 3
*/
