We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

 

Example 1:

Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0
Example 2:

Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01
Example 3:

Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
 

Constraints:

1 <= n <= 30
1 <= k <= 2n - 1


//https://ibb.co/album/JndHR2

/*
tc - O(n)
sc - O(n)

class Solution {
public:
    int depthFirstSearch(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return depthFirstSearch(n - 1, k, nextRootVal);
        }
    }

    int kthGrammar(int n, int k) {
        return depthFirstSearch(n, k, 0);
    }
};

*/
/*
Algorithm
Find the count of the number of 1 bits in k - 1.
Return 0 if count is even, 1 otherwise.


tc - O(logk)
sc - O(1)
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        int count = __builtin_popcount(k-1);
        return count % 2 == 0 ? 0 : 1;
    }
};
/*

0   1   1   0   1   0   0   1
0   1   2   3   4   5   6   7  -- index
0   1   1   2   1   2   2   3  -- NO OF 1 BITS IN INDEX

*/