class Solution {
public:
    int findMin(vector<int>& arr) {
        
    int start = 0, end = arr.size() - 1;
        
    while (start < end) {
      int mid = start + (end - start) / 2;

      // if mid is greater than the next element
      if (mid < end && arr[mid] > arr[mid + 1]) { 
        return arr[mid + 1];
      }

      // if mid is smaller than the previous element
      if (mid > start && arr[mid - 1] > arr[mid]) { 
        return arr[mid];
      }

      if (arr[start] < arr[mid]) {  // left side is sorted, so the pivot is on right side
        start = mid + 1;
      } else {  // right side is sorted, so the pivot is on the left side
        end = mid - 1;
      }
    }

    return arr[0];  // the array has not been rotated
  }
    
};