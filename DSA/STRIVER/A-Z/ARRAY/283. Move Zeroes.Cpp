/*
Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = 0;
        
        for(int j = 0; j < nums.size(); j++){
            
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }
        
        for(int j = i; j < nums.size(); j++){
            nums[j] = 0;
        }
        
    }
};


//2nd approach
#include<bits/stdc++.h>

using namespace std;
void zerosToEnd(int arr[], int n) {

  //finding first zero occurrence
  int k = 0;
  while (k < n) {
    if (arr[k] == 0) {

      break;
    } else {
      k = k + 1;
    }
  }

  //finding zeros and immediate non-zero elements and swapping them
  int i = k, j = k + 1;

  while (i < n && j < n) {
    if (arr[j] != 0) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;

    }

    j++;

  }
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int arr[] ={ 1,2,0,1,0,4,0};
  zerosToEnd(arr, 7);
}