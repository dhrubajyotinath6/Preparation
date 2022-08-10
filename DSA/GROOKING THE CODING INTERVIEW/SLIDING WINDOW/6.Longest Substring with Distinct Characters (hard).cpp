/*
Given a string, find the length of the longest substring, which has all distinct characters.

 Example 1:
Input: String="aabccbb"
Output: 3
Explanation: The longest substring with distinct characters is "abc".
Example 2:

Input: String="abbbb"
Output: 2
Explanation: The longest substring with distinct characters is "ab".
Example 3:

Input: String="abccde"
Output: 3
Explanation: Longest substrings with distinct characters are "abc" & "cde".
*/

/*
    Time Complexity

The above algorithm’s time complexity will be O(N),
where ‘N’ is the number of characters in the input string.

    Space Complexity

The algorithm’s space complexity will be O(K), where K is the number of distinct characters
in the input string.

This also means K <= N, because in the worst case,
the whole string might not have any duplicate character,
so the entire string will be added to the HashMap.

Having said that,
since we can expect a fixed set of characters in the input string (e.g., 26 for English letters),
we can say that the algorithm runs in fixed space O(1);
in this case, we can use a fixed-size array instead of the HashMap.


TC -> O(N)
SC -> O(K)

*/

static int findLength(const string &str)
{

  int windowStart = 0, maxLength = 0;
  unordered_map<char, int> charIndexMap;

  // try to extend the range [windowStart, windowEnd]
  for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
  {

    char rightChar = str[windowEnd];

    // if the map already contains the 'rightChar', shrink the window from the
    // beginning so that we have only one occurrence of 'rightChar'
    if (charIndexMap.find(rightChar) != charIndexMap.end())
    {

      // this is tricky; in the current window, we will not have any 'rightChar' after
      // its previous index and if 'windowStart' is already ahead of the last index of
      // 'rightChar', we'll keep 'windowStart'
      windowStart = max(windowStart, charIndexMap[rightChar] + 1);
    }

    charIndexMap[rightChar] = windowEnd; // insert the 'rightChar' into the map

    // remember the maximum length so far
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }

  return maxLength;
}
