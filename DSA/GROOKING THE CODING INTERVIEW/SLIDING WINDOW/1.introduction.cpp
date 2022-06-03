/*
Given an array, find the average of all  subarrays of ‘K’ contiguous elements in it.


*/

static vector<double> findAverages(int K, const vector<int>& arr) {

    vector<double> result(arr.size() - K + 1);
    
    double windowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      windowSum += arr[windowEnd];  // add the next element
      // slide the window, no need to slide if we've not hit the window size of 'k'
      if (windowEnd >= K - 1) {
        result[windowStart] = windowSum / K;  // calculate the average
        windowSum -= arr[windowStart];        // subtract the element going out
        windowStart++;                        // slide the window ahead
      }
    }

    return result;
  }