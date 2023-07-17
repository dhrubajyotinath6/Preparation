/*
3  -  7 => 3, 4, 5, 6, 7  => 3
2  -  7 => 2, 3, 4, 5, 6, 7 => 3

3  -  4 => 1
3  -  3 => 1
4  -  4 => 1
*/

class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, make it odd.
        if (!(low & 1)) {
            low++;
        }
  
        // low could become greater than high due to incrementation
        // if it is, the answer is 0; otherwise, use the formula.
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};