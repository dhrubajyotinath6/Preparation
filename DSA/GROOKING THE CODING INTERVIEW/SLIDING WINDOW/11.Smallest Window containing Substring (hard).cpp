/*
Given a string and a pattern, find the smallest substring in the given string
which has all the character occurrences of the given pattern.

Example 1:

Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"


Example 2:

Input: String="aabdec", Pattern="abac"
Output: "aabdec"
Explanation: The smallest substring having all characters occurrences of the pattern is "aabdec"


Example 3:

Input: String="abdbca", Pattern="abc"
Output: "bca"
Explanation: The smallest substring having all characters of the pattern is "bca".


Example 4:


Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the pattern

*/

/*
    Time Complexity

The time complexity of the above algorithm will be O(N + M)
where ‘N’ and ‘M’ are the number of characters in the input string and the pattern respectively.

    Space Complexity

The space complexity of the algorithm is O(M) since in the worst case,
the whole pattern can have distinct characters which will go into the HashMap.
In the worst case, we also need O(N)O(N) space for the resulting substring,
which will happen when the input string is a permutation of the pattern.

*/

static string findSubstring(const string &str, const string &pattern)
{
  int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
  unordered_map<char, int> charFrequencyMap;

  for (auto chr : pattern)
  {
    charFrequencyMap[chr]++;
  }

  // try to extend the range [windowStart, windowEnd]
  for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
  {
    char rightChar = str[windowEnd];
    if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
    {
      charFrequencyMap[rightChar]--;
      if (charFrequencyMap[rightChar] >= 0)
      { // count every matching of a character
        matched++;
      }
    }

    // shrink the window if we can, finish as soon as we remove a matched character
    while (matched == pattern.length())
    {
      if (minLength > windowEnd - windowStart + 1)
      {
        minLength = windowEnd - windowStart + 1;
        subStrStart = windowStart;
      }

      char leftChar = str[windowStart++];
      if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
      {
        // note that we could have redundant matching characters, therefore we'll
        // decrement the matched count only when a useful occurrence of a matched
        // character is going out of the window
        if (charFrequencyMap[leftChar] == 0)
        {
          matched--;
        }
        charFrequencyMap[leftChar]++;
      }
    }
  }

  return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
}
