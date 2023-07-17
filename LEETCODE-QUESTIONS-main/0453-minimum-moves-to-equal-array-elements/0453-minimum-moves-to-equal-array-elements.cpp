//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/solution/

//there are various solutions to this problem, approach (1 to 6)
//here i hv done the approach 5

/*
This approach is based on the idea that adding 1 to all the elements 
except one is equivalent to decrementing 1 from a single element, 
since we are interested in the relative levels of the elements which
need to be equalized. Thus, the problem is simplified to find the 
number of decrement operations required to equalize all the elements 
of the given array. For finding this, it is obvious that we'll reduce
all the elements of the array to the minimum element. But, in order to
find the solution, we need not actually decrement the elements. We can
find the number of moves required as 

moves= (i = 0, n-1)∑a[i] -  [min(a)*n],

where n is the length of the array.

            ---------------------
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/solution/381028

Let's explain it in a clear and short manner:

suppose there're k elements, the sum of original array is s, 
the minimum move is m, eventually all the elements become e, 
we know each move contributes (k-1) to the sum, 

so we have:
s + (k-1)*m = k*e

for the minimum element min, it must be added m times, i.e.
min + m = e

The two equations above would give us m = s - k*min

*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum = 0, mini = numeric_limits<int>::max();
        int n = nums.size();
        
        for(auto x : nums){
            sum += x;
            mini = min(mini, x);
        }
        
        int ans = sum - n*mini;
        
        return ans;
    }
};