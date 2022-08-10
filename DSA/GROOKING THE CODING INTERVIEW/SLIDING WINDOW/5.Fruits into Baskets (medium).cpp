/*
You are visiting a farm to collect fruits. The farm has a single row of fruit trees.
You will be given two baskets, and your goal is to pick as many fruits as possible to be placed
in the given baskets.

You will be given an array of characters where each character represents a fruit tree.
The farm has following restrictions:

Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
You can start with any tree, but you can’t skip a tree once you have started.
You will pick exactly one fruit from every tree until you cannot, i.e.,
you will stop when you have to pick from a third fruit type.

*/

/*
Time Complexity
The above algorithm’s time complexity will be O(N), where ‘N’ is the number of characters
in the input array.
The outer 'for' loop runs for all characters,
and the inner 'while' loop processes each character only once;
therefore, the time complexity of the algorithm will be O(N+N),
which is asymptotically equivalent to O(N).

Space Complexity
The algorithm runs in constant space O(1) as there can be a maximum of
three types of fruits stored in the frequency map.

TC -> O(N)
SC -> O(1)

*/

static int findLength(const vector<char> &arr)
{
  int windowStart = 0, maxLength = 0;
  unordered_map<char, int> fruitFrequencyMap;

  // try to extend the range [windowStart, windowEnd]
  for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
  {
    fruitFrequencyMap[arr[windowEnd]]++;

    // shrink the sliding window, until we're left with '2' fruits in the frequency map
    while ((int)fruitFrequencyMap.size() > 2)
    {
      fruitFrequencyMap[arr[windowStart]]--;

      if (fruitFrequencyMap[arr[windowStart]] == 0)
      {
        fruitFrequencyMap.erase(arr[windowStart]);
      }
      windowStart++; // shrink the window
    }

    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }

  return maxLength;
}

/*
Similar Problems
Problem 1: Longest Substring with at most 2 distinct characters

Given a string, find the length of the longest substring in it with at most two distinct characters.

Solution: This problem is exactly similar to our parent problem

*/