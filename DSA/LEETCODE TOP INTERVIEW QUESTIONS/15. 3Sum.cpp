/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

vector<vector<int>> res;
sort(num.begin(), num.end());

// moves for a
for (int i = 0; i < (int)(num.size()) - 2; i++)
{

    if (i == 0 || (i > 0 && num[i] != num[i - 1]))
    {

        int lo = i + 1, hi = (int)(num.size()) - 1, sum = 0 - num[i];

        while (lo < hi)
        {
            if (num[lo] + num[hi] == sum)
            {

                vector<int> temp;
                temp.push_back(num[i]);
                temp.push_back(num[lo]);
                temp.push_back(num[hi]);
                res.push_back(temp);

                while (lo < hi && num[lo] == num[lo + 1])
                    lo++;
                while (lo < hi && num[hi] == num[hi - 1])
                    hi--;

                lo++;
                hi--;
            }
            else if (num[lo] + num[hi] < sum)
                lo++;
            else
                hi--;
        }
    }
}
return res;
}