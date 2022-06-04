Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.

Example 1:

Input: "aappp"
Output: "papap"
Explanation: In "papap", none of the repeating characters come next to each other.
Example 2:

Input: "Programming"
Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
Explanation: None of the repeating characters come next to each other.
Example 3:

Input: "aapa"
Output: ""
Explanation: In all arrangements of "aapa", atleast two 'a' will come together e.g., "apaa", "paaa".



class RearrangeString {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string rearrangeString(const string &str) {
    unordered_map<char, int> charFrequencyMap;
    for (char chr : str) {
      charFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : charFrequencyMap) {
      maxHeap.push(entry);
    }

    pair<char, int> previousEntry(-1, -1);
    string resultString = "";
    while (!maxHeap.empty()) {
      pair<char, int> currentEntry = maxHeap.top();
      maxHeap.pop();
      // add the previous entry back in the heap if its frequency is greater than zero
      if (previousEntry.second > 0) {
        maxHeap.push(previousEntry);
      }
      // append the current character to the result string and decrement its count
      resultString += currentEntry.first;
      currentEntry.second--;
      previousEntry = currentEntry;
    }

    // if we were successful in appending all the characters to the result string, 
    // return it
    return resultString.length() == str.length() ? resultString : "";
  }
};

