/*
https://leetcode.com/problems/sort-characters-by-frequency/

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.


Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


/*
https://leetcode.com/problems/sort-characters-by-frequency/solution/

Approach 3: Multiset and Bucket Sort -- check this

While the heap approach is probably adequate for an interview, there 
is actually a way of solving this problem with a time complexity of 
O(n) which is Approach 3 ^
                         |
                         |
*/

class Solution {
    
public:
  struct valueCompare {
    bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return y.second > x.second;
    }
  };
    
public:
    string frequencySort(string str) {
      
    // find the frequency of each character
    unordered_map<char, int> characterFrequencyMap;
        
    for (char chr : str) {
      characterFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : characterFrequencyMap) {
      maxHeap.push(entry);
    }

    // build a string, appending the most occurring characters first
    string sortedString = "";
    while (!maxHeap.empty()) {
        
      auto entry = maxHeap.top();
      maxHeap.pop();
        
      for (int i = 0; i < entry.second; i++) {
        sortedString += entry.first;
      }
        
    }

    return sortedString;
    }
};






