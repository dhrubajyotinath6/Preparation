//https://leetcode.com/problems/binary-number-with-alternating-bits/solution/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int curr = n%2;
        n /= 2;
        
        while(n > 0){
            if(curr == n%2) return false;
            curr = n%2;
            n /=2;
        }

        return true;
    }
};

some other solutions

1.
return (n & (n >> 1)) == 0 && (n & (n >> 2)) == (n >> 2);

 I think now I understand it after spending some time.
The first part (n & (n >> 1)) == 0 ensures that there is no consecutive ones.

Now we need to ensure that there are no consecutive 0s.
The second part first computes (n & (n >> 2)). If the number has alternating bits, the ones & zeros will align after this operation 
and (n & (n >> 2)) will be equal to (n >> 2).
However, if there is any consecutive zero, it will turn off a 1 bit causing the result not to be equal to (n >> 2).
    
    
 2.
    
    function bitSolution(number){
    //      10101010101
    //  +    1010101010    ( number >> 1 )
    //  ---------------
    //  =   11111111111
    //  &  100000000000
    //  ---------------
    //  =             0    ( power of two )
    let tmp = ( number >> 1 ) + number;
    return (tmp & tmp + 1) === 0;
}

3.
    return (n & (n >> 1)) == 0 && (n | (n >> 2)) == n;
    
    
    
