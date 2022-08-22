/*

https://leetcode.com/problems/largest-palindromic-number/discuss/2456626/CPP-JAVA-or-Greedy-or-O(1)-SPACE-or-O(N)-TIME
VERY VERY IMP

You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.


Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation:
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
Example 2:

Input: num = "00009"
Output: "9"
Explanation:
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.


Constraints:

1 <= num.length <= 105
num consists of digits.

*/

// https://leetcode.com/problems/largest-palindromic-number/discuss/2456626/CPP-JAVA-or-Greedy-or-O(1)-SPACE-or-O(N)-TIME

class Solution
{
public:
    string largestPalindromic(string num)
    {

        vector<int> mpp(10);

        for (auto i : num)
        {
            mpp[i - '0']++;
        }

        string ans = "";
        int single = -1;

        for (int i = 9; i >= 0; i--)
        {

            if (ans.empty() && i == 0)
                continue;

            while (mpp[i] > 1)
            {
                ans.push_back(i + '0');
                mpp[i] -= 2;
            }

            if (mpp[i] == 1 && single == -1)
            {
                single = i;
            }
        }

        string secondPart = string(ans.rbegin(), ans.rend());

        if (ans.empty() && single == -1)
            return "0";

        // if(ans.empty() && single != -1) return to_string(single);

        if (single != -1)
        {
            ans.push_back(single + '0');
        }

        ans += secondPart;

        return ans;
    }
};

/*
Input
"00009"

Output
"00900"

Expected
"9"
*/

/*
Input
"00001105"

Output
"151"

Expected
"1005001"
*/