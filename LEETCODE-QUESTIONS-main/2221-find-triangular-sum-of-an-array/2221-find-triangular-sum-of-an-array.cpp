//https://leetcode.com/problems/find-triangular-sum-of-an-array/discuss/1907380/O(n)-time-O(1)-space-Python-189-ms-C%2B%2B-12-ms-Java-4-ms    --LEGEND

// https://leetcode.com/problems/find-triangular-sum-of-an-array/discuss/1907386/Dedicated-to-Beginners-or-With-explanation -- RECURSION

//https://leetcode.com/problems/find-triangular-sum-of-an-array/discuss/1907038/C%2B%2B-Short-O(1)-extra-space  -- ITERATIVE

/*

    In 1st loop we iterate n-1 times as size of triangle decreases by 1 at every level.
    In second loop we iterate the array and store the sum of nums[j] + nums[j+1] and store it in nums[j]
    Here we modify the same array to store the sum so O(1) space is used.


*/
class Solution {
public:
    int triangularSum(vector<int>& A) {
        
        for (int i = A.size(); i >= 2; --i) {
            for (int j = 0; j < i - 1; ++j) {
                A[j] = (A[j] + A[j + 1]) % 10;
            }
        }
        return A[0];
    }
};