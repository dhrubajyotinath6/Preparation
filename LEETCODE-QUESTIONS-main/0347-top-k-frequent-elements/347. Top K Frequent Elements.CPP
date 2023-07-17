class Solution {
    
  struct valueCompare {
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
          return x.second > y.second;
        }
   };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
    // find the frequency of each number
    unordered_map<int, int> numFrequencyMap;
    for (int n : nums) {
      numFrequencyMap[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

    // go through all numbers of the numFrequencyMap and push them in the minHeap, which 
    // will have top k frequent numbers. If the heap size is more than k, we remove the 
    // smallest (top) number
    for (auto entry : numFrequencyMap) {
      minHeap.push(entry);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    // create a list of top k numbers
    vector<int> topNumbers;
    while (!minHeap.empty()) {
      topNumbers.push_back(minHeap.top().first);
      minHeap.pop();
    }

    return topNumbers;
  }
    
};
