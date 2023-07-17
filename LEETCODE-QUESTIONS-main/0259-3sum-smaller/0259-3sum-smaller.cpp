class Solution {
    
public:
    int searchPair(const vector<int> &arr, int targetSum, int first) {
    int count = 0;
    int left = first + 1, right = arr.size() - 1;
    while (left < right) {
      if (arr[left] + arr[right] < targetSum) {  // found the triplet
        // since arr[right] >= arr[left], therefore, we can replace arr[right] by any 
        // number between left and right to get a sum less than the target sum
        count += right - left;
        left++;
      } else {
        right--;  // we need a pair with a smaller sum
      }
    }
    return count;
  }
public:
    int threeSumSmaller(vector<int>& arr, int target) {
        
    if(arr.size() < 3) return 0;
    
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < arr.size() - 2; i++) {
      count += searchPair(arr, target - arr[i], i);
    }
    return count;
    }
};