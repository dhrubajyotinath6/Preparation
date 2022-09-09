/*
https://leetcode.com/problems/top-k-frequent-elements/solution/   --VERY VERY IMP 

Approach 2: Quickselect (Hoare's selection algorithm)

Further Discussion: Could We Do Worst-Case Linear Time?
In theory, we could, the algorithm is called Median of Medians.

This method is never used in practice because of two drawbacks:


There is in fact O(n) time and space solution, using bucket sort idea: no frequencies can be more than n. 
I think this solution is simpler and better than overcomplicated QuickSelect solution.
For more details see 
https://leetcode.com/problems/top-k-frequent-elements/discuss/740374/Python-5-lines-O(n)-buckets-solution-explained.

*/

Given an unsorted array of numbers, find the top ‘K’ frequently occurring numbers in it.

Example 1:

Input: [1, 3, 5, 12, 11, 12, 11], K = 2
Output: [12, 11]
Explanation: Both '11' and '12' apeared twice.
Example 2:

Input: [5, 12, 11, 3, 11], K = 2
Output: [11, 5] or [11, 12] or [11, 3]
Explanation: Only '11' appeared twice, all other numbers appeared once.




class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
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