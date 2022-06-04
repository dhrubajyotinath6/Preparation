Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array. Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.

Example 1:

Input: [5, 6, 7, 8, 9], K = 3, X = 7
Output: [6, 7, 8]
Example 2:

Input: [2, 4, 5, 6, 9], K = 3, X = 6
Output: [4, 5, 6]
Example 3:

Input: [2, 4, 5, 6, 9], K = 3, X = 10
Output: [5, 6, 9]


APPROACH #1:

class KClosestElements {
 public:
  struct numCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
  };

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    int index = binarySearch(arr, X);
    int low = index - K, high = index + K;
    low = max(low, 0);  // 'low' should not be less than zero
    // 'high' should not be greater the size of the array
    high = min(high, (int)arr.size() - 1); 

    priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> minHeap;
    // add all candidate elements to the min heap, sorted by their absolute difference 
   // from 'X'
    for (int i = low; i <= high; i++) {
      minHeap.push(make_pair(abs(arr[i] - X), i));
    }

    // we need the top 'K' elements having smallest difference from 'X'
    vector<int> result;
    for (int i = 0; i < K; i++) {
      result.push_back(arr[minHeap.top().second]);
      minHeap.pop();
    }

    sort(result.begin(), result.end());
    return result;
  }

 private:
  static int binarySearch(const vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        return mid;
      }
      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (low > 0) {
      return low - 1;
    }
    return low;
  }
};



APPROACH #2:

class KClosestElements {
 public:
  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    deque<int> result;
    int index = binarySearch(arr, X);
    int leftPointer = index;
    int rightPointer = index + 1;
    for (int i = 0; i < K; i++) {
      if (leftPointer >= 0 && rightPointer < (int)arr.size()) {
        int diff1 = abs(X - arr[leftPointer]);
        int diff2 = abs(X - arr[rightPointer]);
        if (diff1 <= diff2) {
          result.push_front(arr[leftPointer--]);  // append in the beginning
        } else {
          result.push_back(arr[rightPointer++]);  // append at the end
        }
      } else if (leftPointer >= 0) {
        result.push_front(arr[leftPointer--]);
      } else if (rightPointer < (int)arr.size()) {
        result.push_back(arr[rightPointer++]);
      }
    }
    vector<int> resultVec;
    std::move(std::begin(result), std::end(result), std::back_inserter(resultVec));
    return resultVec;
  }

 private:
  static int binarySearch(const vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        return mid;
      }
      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (low > 0) {
      return low - 1;
    }
    return low;
  }
};