class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>squares(n);
        
        int left = 0, right = n-1, i = n-1;
        
        while(left <= right){
            
            int leftSquares = nums[left]*nums[left];
            int rightSquares = nums[right]*nums[right];
            
            if(leftSquares <= rightSquares){
                squares[i--] = rightSquares;
                right--;
            }
            
            else if(leftSquares > rightSquares){
                squares[i--] = leftSquares;
                left++;
            }
        }
        
        return squares;
    }
};