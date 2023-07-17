class Solution {
public:
    
    int findSquareSum(int num) {
        
    int sum = 0, digit;
        
    while (num > 0) {
        
      digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }
        
    return sum;
        
    }
    
    bool isHappy(int num) {
        
    int slow = num, fast = num;
        
    do {
      slow = findSquareSum(slow);                 // move one step
      fast = findSquareSum(findSquareSum(fast));  // move two steps
    } while (slow != fast);                       // found the cycle

    return slow == 1; 
        
    }
};