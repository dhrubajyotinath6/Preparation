Given an array of numbers and a number ‘K’, we need to remove ‘K’ numbers from the array such that we are left with maximum distinct numbers.

Example 1:

Input: [7, 3, 5, 8, 5, 3, 3], and K=2
Output: 3
Explanation: We can remove two occurrences of 3 to be left with 3 distinct numbers [7, 3, 8], we have 
to skip 5 because it is not distinct and occurred twice. 
Another solution could be to remove one instance of '5' and '3' each to be left with three distinct numbers [7, 5, 8], in this case, we have to skip 3 because it occurred twice.
Example 2:

Input: [3, 5, 12, 11, 12], and K=3
Output: 2
Explanation: We can remove one occurrence of 12, after which all numbers will become distinct. Then we can delete any two numbers which will leave us 2 distinct numbers in the result.
Example 3:

Input: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], and K=2
Output: 3
Explanation: We can remove one occurrence of '4' to get three distinct numbers.




class MaximumDistinctElements {
 public:
  struct valueCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

  static int findMaximumDistinctElements(const vector<int> &nums, int k) {
    int distinctElementsCount = 0;
    if (nums.size() <= k) {
      return distinctElementsCount;
    }

    // find the frequency of each number
    unordered_map<int, int> numFrequencyMap;
    for (auto i : nums) {
      numFrequencyMap[i]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

    // insert all numbers with frequency greater than '1' into the min-heap
    for (auto entry : numFrequencyMap) {
      if (entry.second == 1) {
        distinctElementsCount++;
      } else {
        minHeap.push(entry);
      }
    }

    // following a greedy approach, try removing the least frequent numbers first from 
    // the min-heap
    while (k > 0 && !minHeap.empty()) {
      auto entry = minHeap.top();
      minHeap.pop();
      // to make an element distinct, we need to remove all of its occurrences except one
      k -= entry.second - 1;
      if (k >= 0) {
        distinctElementsCount++;
      }
    }

    // if k > 0, this means we have to remove some distinct numbers
    if (k > 0) {
      distinctElementsCount -= k;
    }

    return distinctElementsCount;
  }
};