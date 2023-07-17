/*
https://leetcode.com/problems/shuffle-the-array/solution/

The second approach works only because of the constraints i.e. 
nums[i] is less than 10^3, but this approach won't follow up 
if our constraint will become something like 10^9.


It will work but in that case each element of the array needs to be of type long long
*/

/*
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        
        for(int i = 0; i < n; i++){
            ans[2*i] = nums[i];
            ans[2*i + 1] = nums[n + i];
        }
        
        return ans;
    }
};

*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

         // Store each y(i) with respective x(i).
        for(int i = n; i < 2*n; i++){
            int secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }
        
         // '0000000000 1111111111' in decimal.
        int allOnes = pow(2,10) - 1;
        
        for(int i = n-1; i >= 0; i--){
            
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & allOnes;
            
            nums[2*i + 1] = secondNum;
            nums[2*i] = firstNum;
        }
        
        return nums;
    }
};