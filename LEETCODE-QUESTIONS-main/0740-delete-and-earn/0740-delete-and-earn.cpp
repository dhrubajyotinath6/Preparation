class Solution {
    
public:
    //0   0   4    9     4
    int findMaxSteal(vector<int> &wealth) {
        
    if (wealth.empty()) {
      return 0;
    }
        
    int n1 = 0, n2 = wealth[0], temp;
        
    for (int i = 1; i < wealth.size(); i++) {
      temp = max(n1 + wealth[i], n2);
      n1 = n2;
      n2 = temp;
    }
        
     return n2;
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        
       int maxi = nums[0];
       for(auto& num : nums){
           maxi = max(maxi, num);
       }
        
       vector<int> gold(maxi + 1);
       for(auto& num : nums){
           gold[num] += num;
       }
        
       return findMaxSteal(gold);
        
    }
};