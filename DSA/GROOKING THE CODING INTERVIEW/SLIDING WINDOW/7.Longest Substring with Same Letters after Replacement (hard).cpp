/*
Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters
with any letter, find the length of the longest substring having the same letters after replacement.

Example 1:

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".


Example 2:

Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".


Example 3:

Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".

*/

/*
    Time Complexity

The above algorithm’s time complexity will be O(N),
where ‘N’ is the number of letters in the input string.

    Space Complexity

As we expect only the lower case letters in the input string,
we can conclude that the space complexity will be O(26) to store each letter’s frequency in the HashMap,
which is asymptotically equal to O(1)

TC -> O(N)
SC -> O(1)
*/

static int findLength(const string &str, int k)
{

  int windowStart = 0, maxLength = 0, maxRepeatLetterCount = 0;
  unordered_map<char, int> letterFrequencyMap;

  // try to extend the range [windowStart, windowEnd]
  for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
  {
    char rightChar = str[windowEnd];
    letterFrequencyMap[rightChar]++;

    // we don't need to place the maxRepeatLetterCount under the below 'if', see the
    // explanation in the 'Solution' section above.
    maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[rightChar]);

    // current window size is from windowStart to windowEnd, overall we have a letter
    // which is repeating 'maxRepeatLetterCount' times, this means we can have a window
    //  which has one letter repeating 'maxRepeatLetterCount' times and the remaining
    // letters we should replace. If the remaining letters are more than 'k', it is the
    // time to shrink the window as we are not allowed to replace more than 'k' letters
    if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k)
    {
      char leftChar = str[windowStart];
      letterFrequencyMap[leftChar]--;
      windowStart++;
    }

    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }

  return maxLength;
}
