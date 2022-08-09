/*
You are given an integer n and an integer start.

Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.



Example 1:

Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.
Example 2:

Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.

*/

/*
TRY TO RUN TC->O(1)
           SC->O(1)

*/

// https://leetcode.com/problems/xor-operation-in-an-array/discuss/697849/O(1)-time

// https://leetcode.com/problems/xor-operation-in-an-array/discuss/862065/c%2B%2B-0ms-easy-solution   --FRIENDLY

class Solution
{
public:
    int xorOperation(int n, int start)
    {

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // ans = ans ^ start + 2*i;
            // ans ^= start + 2*i;
            ans ^= start + (i << 1);
        }

        return ans;
    }
};

/*
But if you omit the bracket, addition will happen first, as it has higher precedence than bitwise shift.
That is

x ^= start + i << 1;
is equivalent to

x ^= (start + i) << 1;


*/