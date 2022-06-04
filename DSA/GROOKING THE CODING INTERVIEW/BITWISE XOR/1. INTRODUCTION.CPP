XOR is a logical bitwise operator that returns 0 (false) 
if both bits are the same and returns 1 (true) otherwise


Given an array of n-1n−1 integers in the range from 11 to nn, find the one number that is missing from the array.

ALGO:
    XOR all the numbers from 1 to n, let’s call it x1.
    XOR all the numbers in the input array, let’s call it x2.
    The missing number can be found by x1 XOR x2.

class MissingNumber {
public:
  static int findMissingNumber(vector<int> &arr) {
    int n = arr.size() + 1;
    // x1 represents XOR of all values from 1 to n
    int x1 = 1;
    for (int i = 2; i <= n; i++)
      x1 = x1 ^ i;

    // x2 represents XOR of all values in arr
    int x2 = arr[0];
    for (int i = 1; i < n-1; i++)
      x2 = x2 ^ arr[i];

    // missing number is the xor of x1 and x2
    return x1 ^ x2;
  }
};

