/*
https://leetcode.com/problems/cutting-ribbons/discuss/1263437/Java-Simple-Binary-Search-%2B-Explanation

*/

class Solution {
    
    bool isCutPossible(vector<int>& ribbons, int length, int k){
        
        int count = 0;
        
        for (int ribbon : ribbons){
            count += (ribbon/length);
        }
        
        return count >= k;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
        
        int low = 1;
        int high = INT_MAX;
        
        while(low < high){
            
            int mid = low + ((high - low) >> 2);
            
            if(!isCutPossible(ribbons, mid, k)){
                high = mid;
            }
            else {
               low = mid + 1; 
            }
        }
        return low - 1;
    }
    };
