//https://leetcode.com/problems/minimize-deviation-in-array/solution/   - 5 APPROCHES ARE THERE , I HV DONE ONLY 1ST APPROACH

//https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> evens;
        int mini = INT_MAX;
        
        for(auto& num : nums){
            if(num % 2 == 0){
                evens.push(num);
                mini = min(mini, num);
            }else{
                evens.push(num*2);
                mini = min(mini, num*2);
            }
        }
        
        int minDeviation = INT_MAX;
        
        while(!evens.empty()){
            int currValue = evens.top();
            evens.pop();
            
            minDeviation = min(minDeviation, currValue - mini);
        
            if(currValue % 2 == 0){
                evens.push(currValue/2);
                mini = min(mini, currValue/2);
            }else{
                break;
            }
        }
        
        return minDeviation;
    }
};