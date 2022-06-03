Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.

Example 1:

Input: 23   
Output: true (23 is a happy number)  
Explanations: Here are the steps to find out that 23 is a happy number:

Example 2:

Input: 12   
Output: false (12 is not a happy number)  
Explanations: Here are the steps to find out that 12 is not a happy number:

The process, defined above, to find out if a number is a happy number or not, always ends in a cycle. 
If the number is a happy number, the process will be stuck in a cycle on number ‘1,’ and 
if the number is not a happy number then the process will be stuck in a cycle with a set of numbers.
 As we saw in Example-2 while determining if ‘12’ is a happy number or not, 
 our process will get stuck in a cycle with the following numbers: 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89


 class HappyNumber {
 public:
  static bool find(int num) {
    int slow = num, fast = num;
    do {
      slow = findSquareSum(slow);                 // move one step
      fast = findSquareSum(findSquareSum(fast));  // move two steps
    } while (slow != fast);                       // found the cycle

    return slow == 1;  // see if the cycle is stuck on the number '1'
  }

 private:
  static int findSquareSum(int num) {
    int sum = 0, digit;
    while (num > 0) {
      digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }
    return sum;
  }
};


