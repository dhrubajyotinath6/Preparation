class Solution {
public:
    int threeSumClosest(vector<int>& arr, int targetSum) {
        
    sort(arr.begin(), arr.end());        
    int smallestDifference = numeric_limits<int>::max();
        
    for (int i = 0; i < arr.size() - 2; i++) {
        
      int left = i + 1, right = arr.size() - 1;
        
      while (left < right) {
        
        int targetDiff = targetSum - arr[i] - arr[left] - arr[right];
        if (targetDiff == 0) {  //  we've found a triplet with an exact sum
          return targetSum;  // return sum of all the numbers
        }

        if (abs(targetDiff) < abs(smallestDifference)) {
          smallestDifference = targetDiff;  // save the closest difference
        }

        if (targetDiff > 0) {
          left++;  // we need a triplet with a bigger sum
        } else {
          right--;  // we need a triplet with a smaller sum
        }
      }
    }
    return targetSum - smallestDifference;
  }
    
};