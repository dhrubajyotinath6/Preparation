In a non-empty array of integers, every number appears twice except for one, find that single number.

Example 1:

Input: 1, 4, 2, 1, 3, 2, 3
Output: 4
Example 2:

Input: 7, 9, 7
Output: 9


It returns zero if we take XOR of two same numbers.
It returns the same number if we XOR with zero.
So we can XOR all the numbers in the input; duplicate numbers will zero out each other 
    and we will be left with the single number




using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      int num = 0;
      for (int i=0; i < arr.size(); i++) {
        num = num ^ arr[i];
      }
      return num;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}