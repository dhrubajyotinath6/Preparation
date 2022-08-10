/*
Given a string and a pattern, find out if the string contains any permutation of the pattern.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.


Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.


Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.


Example 4:

Input: String="aaacb", Pattern="abc"
Output: true
*/

/*
    Time Complexity

The above algorithm’s time complexity will be O(N + M),
where ‘N’ and ‘M’ are the number of characters in the input string and the pattern, respectively.

    Space Complexity

The algorithm’s space complexity is O(M) since, in the worst case,
the whole pattern can have distinct characters that will go into the HashMap.

*/

static bool findPermutation(const string &str, const string &pattern)
{
  int windowStart = 0, matched = 0;
  unordered_map<char, int> charFrequencyMap;

  for (auto chr : pattern)
  {
    charFrequencyMap[chr]++;
  }

  // our goal is to match all the characters from the 'charFrequencyMap' with the
  // current window try to extend the range [windowStart, windowEnd]
  for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
  {
    char rightChar = str[windowEnd];
    if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
    {
      // decrement the frequency of the matched character
      charFrequencyMap[rightChar]--;
      if (charFrequencyMap[rightChar] == 0)
      { // character is completely matched
        matched++;
      }
    }

    if (matched == (int)charFrequencyMap.size())
    {
      return true;
    }

    if (windowEnd >= pattern.length() - 1)
    { // shrink the window
      char leftChar = str[windowStart++];
      if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
      {
        if (charFrequencyMap[leftChar] == 0)
        {
          matched--; // before putting the character back, decrement the matched count
        }
        // put the character back for matching
        charFrequencyMap[leftChar]++;
      }
    }
  }

  return false;
}
