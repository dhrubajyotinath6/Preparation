class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int leftPointer = 0, rightPointer = numbers.size() - 1;
        
        vector<int> ans;
        
        while(leftPointer < rightPointer){
            
            int sum = numbers[leftPointer] + numbers[rightPointer];
            
            if(sum == target){
                ans.push_back(leftPointer + 1);
                ans.push_back(rightPointer + 1);
                return ans;
            }
            
            else if(sum > target) rightPointer--;
            
            //sum < target
            else  leftPointer++;
            
        }
        
        return ans;
    }
};