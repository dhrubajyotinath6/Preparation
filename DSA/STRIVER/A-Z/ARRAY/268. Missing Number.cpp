
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.


Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
2 is the missing number in the range since it does not appear in nums.


Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 
8 is the missing number in the range since it does not appear in nums.


******CAN BE SOLVED USING COUNTING SORT ALSO ********

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int xor1 = 0;
        
        for(int i = 1; i <= n; i++){
            xor1 ^= i;
        }
        
        int xor2 = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            xor2 ^= nums[i];
        }
        
        return xor1^xor2;
    }
};

---------------------

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

