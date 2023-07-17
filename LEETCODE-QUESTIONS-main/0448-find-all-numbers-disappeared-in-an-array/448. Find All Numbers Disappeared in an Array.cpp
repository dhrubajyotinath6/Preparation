Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]


class Solution {
    
public:
  void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
    
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        //cyclic sort
        int i = 0;
        while (i < nums.size()) {
          if (nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
          } else {
            i++;
          }
        }

    vector<int> missingNumbers;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        missingNumbers.push_back(i + 1);
      }
    }

    return missingNumbers;
    }
};

