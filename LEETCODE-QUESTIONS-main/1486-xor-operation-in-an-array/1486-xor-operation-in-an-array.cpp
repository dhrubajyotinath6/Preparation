/*
TRY TO RUN TC->O(1)
           SC->O(1)

*/

//https://leetcode.com/problems/xor-operation-in-an-array/discuss/697849/O(1)-time

//https://leetcode.com/problems/xor-operation-in-an-array/discuss/862065/c%2B%2B-0ms-easy-solution   --FRIENDLY
class Solution {
public:
    int xorOperation(int n, int start) {
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            // ans = ans ^ start + 2*i;
            // ans ^= start + 2*i;
            ans ^= start + (i << 1);
        }
        
        return ans;
    }
};

/*
But if you omit the bracket, addition will happen first, as it has higher precedence than bitwise shift. That is

x ^= start + i << 1;
is equivalent to

x ^= (start + i) << 1;


*/