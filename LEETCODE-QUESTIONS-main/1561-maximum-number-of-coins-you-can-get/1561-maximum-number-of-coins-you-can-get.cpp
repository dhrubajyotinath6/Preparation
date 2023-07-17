//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/discuss/806730/JavaC%2B%2BPython-Stright-Forward

/*
Intuition
We want to compare the numbers, we need to sort.
We give the smallest values Bob,
give the biggest to Alice,
and leave the second biggest to us.
Then we repeat this process.


Explanation
We give small value to Bob,
give the large value to Alice,
and we pick the medium values.

The final assignment will be like:
S S S S S S M L M L M L M L M L

The first third part is given to Bob,
start from A[n/3], we pick one element from every two.


Complexity
Time O(sort)
Space O(sort)

*/
class Solution {
public:
    int maxCoins(vector<int>& A) {
        
        sort(A.begin(), A.end());
        
        int res = 0, n = A.size();
        
        for (int i = n / 3; i < n; i += 2)
            res += A[i];
        return res;
    }
};