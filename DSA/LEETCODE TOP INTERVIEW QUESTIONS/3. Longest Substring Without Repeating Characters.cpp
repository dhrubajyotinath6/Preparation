/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int windowStart = 0, maxLength = 0;
        unordered_map<char, int> mpp;

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++)
        {

            char rightChar = s[windowEnd];

            // if it is in the mpp
            if (mpp.find(rightChar) != mpp.end())
            {

                windowStart = max(windowStart, mpp[rightChar] + 1);
            }

            mpp[rightChar] = windowEnd;

            maxLength = max(windowEnd - windowStart + 1, maxLength);
        }

        return maxLength;
    }
};