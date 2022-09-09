/*
Kth Smallest Number in a Sorted Matrix (Hard)


Problem Statement

Given an N * NN∗N matrix where each row and column is sorted in ascending order, 
find the Kth smallest element in the matrix.

Example 1:

Input: Matrix=[
    [2, 6, 8], 
    [3, 7, 10],
    [5, 8, 11]
  ], 
  K=5
Output: 7
Explanation: The 5th smallest number in the matrix is 7.

Solution

This problem follows the K-way merge pattern and can be easily converted to Kth Smallest Number in 
M Sorted Lists. As each row (or column) of the given matrix can be seen as a sorted list, 
we essentially need to find the Kth smallest number in ‘N’ sorted lists
*/

class KthSmallestInSortedMatrix {
 public:
  struct numCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };

  static int findKthSmallest(vector<vector<int>> &matrix, int k) {

    int n = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (int i = 0; i < n && i < k; i++) {
      minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
    }

    // take the smallest element form the min heap, if the running count is equal to k 
    // return the number if the row of the top element has more elements, add the next 
    // element to the heap
    int numberCount = 0, result = 0;

    while (!minHeap.empty()) {

      auto heapTop = minHeap.top();
      minHeap.pop();

      result = heapTop.first;

      if (++numberCount == k) {
        break;
      }

      heapTop.second.second++;

      if (n > heapTop.second.second) {
        heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
        minHeap.push(heapTop);
      }
    }
    return result;
  }
};