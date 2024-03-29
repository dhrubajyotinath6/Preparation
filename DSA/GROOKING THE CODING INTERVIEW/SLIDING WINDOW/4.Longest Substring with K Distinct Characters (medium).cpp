/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.

You can assume that K is less than or equal to the length of the given string.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

*/

/*
      Time Complexity

The above algorithm’s time complexity will be O(N), where N is the number of characters in the input string.
The outer for loop runs for all characters, and the inner while loop processes each character only once;
therefore, the time complexity of the algorithm will be O(N+N),
which is asymptotically equivalent to O(N).

      Space Complexity

The algorithm’s space complexity is O(K)O(K),
as we will be storing a maximum of K+1 characters in the HashMap.


TC -> O(N)
SC -> O(K)

*/

static int findLength(const string &str, int k)
{
  int windowStart = 0, maxLength = 0;
  unordered_map<char, int> charFrequencyMap;

  // in the following loop we'll try to extend the range [windowStart, windowEnd]
  for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
  {
    char rightChar = str[windowEnd];
    charFrequencyMap[rightChar]++;

    // shrink the sliding window, until we are left with 'k' distinct characters in
    // the frequency map
    while ((int)charFrequencyMap.size() > k)
    {
      char leftChar = str[windowStart];
      charFrequencyMap[leftChar]--;
      if (charFrequencyMap[leftChar] == 0)
      {
        charFrequencyMap.erase(leftChar);
      }
      windowStart++; // shrink the window
    }

    // remember the maximum length so far
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }

  return maxLength;
}