/*
Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from 
the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7.

Solution

This problem follows the K-way merge pattern and we can follow a similar approach as discussed in Merge K Sorted Lists.

We can start merging all the arrays, but instead of inserting numbers into a merged list, 
we will keep count to see how many elements have been inserted in the merged list. 
Once that count is equal to ‘K’, we have found our required number.

A big difference from Merge K Sorted Lists is that in this problem, the input is a list of arrays compared to LinkedLists. 
This means that when we want to push the next number in the heap we need to know what the index of the current number 
in the current array was. To handle this, we will need to keep track of the array and the element indices.

*/


class KthSmallestInMSortedArrays {

 public:

  struct valueCompare {
    bool operator()(const pair<int, pair<int, int>> &x,const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }

  };

  static int findKthSmallest(const vector<vector<int>> &lists, int k) {
    
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, valueCompare> minHeap;

    // put the 1st element of each array in the min heap
    for (int i = 0; i < lists.size(); i++) {
      if (!lists[i].empty()) {
        minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
      }
    }

    // take the smallest (top) element form the min heap, if the running count is equal 
    // to k return the number if the array of the top element has more elements, add the 
    // next element to the heap
    int numberCount = 0, result = 0;

    while (!minHeap.empty()) {

      auto node = minHeap.top();
      minHeap.pop();
      result = node.first;

      if (++numberCount == k) {
        break;
      }

      node.second.second++;
      
      if (lists[node.second.first].size() > node.second.second) {
        node.first = lists[node.second.first][node.second.second];
        minHeap.push(node);
      }
    }

    return result;
  }
};

