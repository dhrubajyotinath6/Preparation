Given a string and a number ‘K’, find if the string can be rearranged such that the same characters are at least ‘K’ distance apart from each other.

Example 1:

Input: "mmpp", K=2
Output: "mpmp" or "pmpm"
Explanation: All same characters are 2 distance apart.
Example 2:

Input: "Programming", K=3
Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more  
Explanation: All same characters are 3 distance apart.
Example 3:

Input: "aab", K=2
Output: "aba"
Explanation: All same characters are 2 distance apart.
Example 4:

Input: "aappa", K=3
Output: ""
Explanation: We cannot find an arrangement of the string where any two 'a' are 3 distance apart.




class RearrangeStringKDistanceApart {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string reorganizeString(const string &str, int k) {
    if (k <= 1) return str;
    
    unordered_map<char, int> charFrequencyMap;
    for (char chr : str) {
      charFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : charFrequencyMap) {
      maxHeap.push(entry);
    }

    queue<pair<char, int>> queue;
    string resultString;
    while (!maxHeap.empty()) {
      auto currentEntry = maxHeap.top();
      maxHeap.pop();
      // append the current character to the result string and decrement its count
      resultString += currentEntry.first;
      currentEntry.second--;
      queue.push(currentEntry);
      if (queue.size() == k) {
        auto entry = queue.front();
        queue.pop();
        if (entry.second > 0) {
          maxHeap.push(entry);
        }
      }
    }

    // if we were successful in appending all the characters to the result string, 
    // return it
    return resultString.length() == str.length() ? resultString : "";
  }
};

