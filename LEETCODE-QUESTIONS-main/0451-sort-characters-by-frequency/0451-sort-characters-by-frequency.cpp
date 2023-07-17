
/*
https://leetcode.com/problems/sort-characters-by-frequency/solution/

Approach 3: Multiset and Bucket Sort -- check this

While the heap approach is probably adequate for an interview, there 
is actually a way of solving this problem with a time complexity of 
O(n).

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






