Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates.

Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.

Example 1:

Input: [4, 6, 10], key = 10
Output: 2
Example 2:

Input: [1, 2, 3, 4, 5, 6, 7], key = 5
Output: 4
Example 3:

Input: [10, 6, 4], key = 10
Output: 0
Example 4:

Input: [10, 6, 4], key = 4
Output: 2



class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    bool isAscending = arr[start] < arr[end];
    while (start <= end) {
      // calculate the middle of the current range
      int mid = start + (end - start) / 2;

      if (key == arr[mid]) {
        return mid;
      }

      if (isAscending) {  // ascending order
        if (key < arr[mid]) {
          end = mid - 1;    // the 'key' can be in the first half
        } else {            // key > arr[mid]
          start = mid + 1;  // the 'key' can be in the second half
        }
      } else {  // descending order
        if (key > arr[mid]) {
          end = mid - 1;    // the 'key' can be in the first half
        } else {            // key < arr[mid]
          start = mid + 1;  // the 'key' can be in the second half
        }
      }
    }
    return -1;  // element not found
  }
};
