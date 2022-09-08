/*
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2,
otherwise, you have to subtract 1 from it.



Example 1:

Input: num = 14
Output: 6
Explanation:
Step 1) 14 is even; divide by 2 and obtain 7.
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3.
Step 4) 3 is odd; subtract 1 and obtain 2.
Step 5) 2 is even; divide by 2 and obtain 1.
Step 6) 1 is odd; subtract 1 and obtain 0.



Example 2:

Input: num = 8
Output: 4
Explanation:
Step 1) 8 is even; divide by 2 and obtain 4.
Step 2) 4 is even; divide by 2 and obtain 2.
Step 3) 2 is even; divide by 2 and obtain 1.
Step 4) 1 is odd; subtract 1 and obtain 0.



Example 3:

Input: num = 123
Output: 12

*/

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/solution/   -- VERY IMP

class Solution
{
public:
    int numberOfSteps(int num)
    {

        if (num == 0)
            return 0;

        int steps = 0;

        for (int powerOfTwo = 1; powerOfTwo <= num; powerOfTwo = powerOfTwo * 2){

            // if((powerOfTwo & num) == 1) steps += 2; //-> doesnot work
            if ((powerOfTwo & num) != 0)
                steps += 2;

            else
                steps += 1;
        }

        return steps - 1;
    }
};