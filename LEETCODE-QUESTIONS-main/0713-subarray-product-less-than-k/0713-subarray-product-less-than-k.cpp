class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int target) {
        
    vector<vector<int>> result;
    double product = 1;
        
    int left = 0;
        
    int count = 0;
        
    for (int right = 0; right < arr.size(); right++) {
        
      product *= arr[right];
        
      while (product >= target && left < arr.size()) {
        product /= arr[left++];
      }
 
      
      for (int i = right; i >= left; i--) {
        count++;
      }
    }
    return count;
    }
};