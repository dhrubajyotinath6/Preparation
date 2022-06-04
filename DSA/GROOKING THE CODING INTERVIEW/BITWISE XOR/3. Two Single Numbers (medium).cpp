In a non-empty array of numbers, every number appears exactly twice except two numbers that appear only once. 
Find the two numbers that appear only once.

Example 1:

Input: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5]
Output: [4, 6]
Example 2:

Input: [2, 1, 3, 2]
Output: [1, 3]





1. Taking XOR of all numbers in the given array will give us 
XOR of num1 and num2, calling this XOR as n1xn2.
2. Find any bit which is set in n1xn2. We can take the rightmost bit which is ‘1’. 
Let’s call this rightmostSetBit. 
3. Iterate through all numbers of the input array to partition them into two groups based on rightmostSetBit.
Take XOR of all numbers in both the groups separately. Both these XORs are our required numbers.






using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
    // get the XOR of the all the numbers
    int n1xn2 = 0;
    for (int num : nums) {
      n1xn2 ^= num;
    }

    // get the rightmost bit that is '1'
    int rightmostSetBit = 1;
    while ((rightmostSetBit & n1xn2) == 0) {
      rightmostSetBit = rightmostSetBit << 1;
    }
    int num1 = 0, num2 = 0;
    for (int num : nums) {
      if ((num & rightmostSetBit) != 0) // the bit is set
        num1 ^= num;
      else // the bit is not set
        num2 ^= num;
    }
    return vector<int>{num1, num2};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}