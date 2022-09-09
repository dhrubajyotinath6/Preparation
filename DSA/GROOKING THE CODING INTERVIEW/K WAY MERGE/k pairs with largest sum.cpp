/*
Given two sorted arrays in descending order, find ‘K’ pairs with the largest sum where each pair 
consists of numbers from both the arrays.

Example 1:

Input: L1=[9, 8, 2], L2=[6, 3, 1], K=3
Output: [9, 3], [9, 6], [8, 6] 
Explanation: These 3 pairs have the largest sum. No other pair has a sum larger than any of these.


Example 2:

Input: L1=[5, 2, 1], L2=[2, -1], K=3
Output: [5, 2], [5, -1], [2, 2]

Solution

This problem follows the K-way merge pattern and we can follow a similar approach 
as discussed in Merge K Sorted Lists.

We can go through all the numbers of the two input arrays to create pairs and initially 
insert them all in the heap until we have ‘K’ pairs in Min Heap. After that, if a pair is bigger 
than the top (smallest) pair in the heap, we can remove the smallest pair 
and insert this pair in the heap.

We can optimize our algorithms in two ways:

Instead of iterating over all the numbers of both arrays, we can iterate only the first ‘K’ numbers 
from both arrays. 
Since the arrays are sorted in descending order, the pairs with the maximum sum will be constituted 
by the first ‘K’ numbers from both the arrays.
As soon as we encounter a pair with a sum that is smaller than the smallest (top) element of the heap, 
we don’t need to process the next elements of the array. Since the arrays are sorted in descending order,
we won’t be able to find a pair with a higher sum moving forward.

*/

class LargestPairs {
 public:
  struct sumCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.first + x.second > y.first + y.second;
    }
  };

  static vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1, vector<pair<int, int>> minHeap;
   
    for (int i = 0; i < nums1.size() && i < k; i++) {
      for (int j = 0; j < nums2.size() && j < k; j++) {

        if (minHeap.size() < k) {
          minHeap.push_back(make_pair(nums1[i], nums2[j]));
          push_heap(minHeap.begin(), minHeap.end(), sumCompare());
        } else {

          // if the sum of the two numbers from the two arrays is smaller than the 
          // smallest (top) element of the heap, we can 'break' here. Since the arrays 
          // are sorted in the descending order, we'll not be able to find a pair with a 
          // higher sum moving forward.
          if (nums1[i] + nums2[j] < minHeap.front().first + minHeap.front().second) {
            break;
          } 
          else {  // else: we have a pair with a larger sum, remove top and insert this
                    // pair in the heap
            pop_heap(minHeap.begin(), minHeap.end(), sumCompare());
            minHeap.pop_back();
            minHeap.push_back(make_pair(nums1[i], nums2[j]));
            push_heap(minHeap.begin(), minHeap.end(), sumCompare());
          }

        }
      }
    }
    return minHeap;
  }
};