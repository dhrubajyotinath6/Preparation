//https://leetcode.com/problems/maximum-69-number/

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change



class Solution {
public:
    int maximum69Number (int num) {
        // Convert the input 'num' to a string 'numString'.
        string numString = to_string(num);

        // Iterate over the string (from high to low).
        for (auto &currChar : numString) {
            // If we find the first '6', replace it with '9' and break the loop.
            if (currChar == '6') {
                currChar = '9';
                break;
            }
        }

        // Convert the modified string to integer and return it.
        return stoi(numString);
    }
};



----------------------------

class Solution {
public:
    int maximum69Number (int num) {
        // Since we start with the lowest digit, initialize currDigit = 0.
        int numCopy = num;
        int indexFirstSix = -1;
        int currDigit = 0;
        
        // Check every digit of 'numCopy' from low to high.
        while (numCopy > 0) {
            // If the current digit is '6', record it as the highest digit of 6.
            if (numCopy % 10 == 6)
                indexFirstSix = currDigit;

            // Move on to the next digit.
            numCopy /= 10;
            currDigit++;
        }

        // If we don't find any digit of '6', return the original number,
        // otherwise, increment 'num' by the difference made by the first '6'.
        // There might be precision loss in pow function if 'indexFirstSix' is large,
        // we can write a for loop to avoid the precision loss.
        return indexFirstSix == -1 ? num : num + 3 * (int)pow(10, indexFirstSix);
    }
};


