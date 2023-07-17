//https://leetcode.com/problems/valid-perfect-square/solution/
/*
 4 -> 2
 25 -> 5
 
 so search space is 2 - 25/2
 
*/

/*
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num < 2) return true;
        
        long left = 2, right = num/2, mid, guessSqu;
        
        while(left <= right){
            mid = left + (right-left)/2;
            guessSqu = mid*mid;
            
            if(guessSqu == num)  return true;
            
            if(guessSqu > num) right = mid -1;
            else left = mid+1;
        }
        
        return false;
    }
};
*/

//Approach 2: Newton's Method
class Solution {
public:
    bool isPerfectSquare(int num) {
        
    if (num < 2) return true;

    long x = num / 2;
    while (x * x > num) {
      x = (x + num / x) / 2;
    }
    return (x * x == num);
        
    }
};
