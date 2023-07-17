/*
we can note that this product will be maximum only if all the numbers 
in numsnums array are positive. But, in the given problem statement, 
negative elements could exist as well.


Thus, it could also be possible that two negative numbers lying at 
the left extreme end could also contribute to lead to a larger 
product if the third number in the triplet being considered is the 
largest positive number in the numsnums array.

https://leetcode.com/problems/maximum-product-of-three-numbers/solution/
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for(auto &n : nums){
            
            if(n < min1){
                min2 = min1;
                min1 = n;
            }else if(n < min2){        // n lies between min1 and min2
                min2 = n;
            }
            
            if (n > max1) {            // n is greater than max1, max2 and max3
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {     // n lies betweeen max1 and max2
                max3 = max2;
                max2 = n;
            } else if (n > max3) {     // n lies betwen max2 and max3
                max3 = n;
            }
        }
        
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};