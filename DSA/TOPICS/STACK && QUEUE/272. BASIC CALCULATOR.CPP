/*

https://leetcode.com/problems/basic-calculator-ii/solution/   -- VERY IMP

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/


//1st Approach


class Solution {
public:
    int calculate(string s) {

        int len = s.length();
        if (len == 0) return 0;

        stack<int> stack;

        int currentNumber = 0;
        char operation = '+';

        for (int i = 0; i < len; i++) {

            char currentChar = s[i];

            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }

            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {

                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }

                operation = currentChar;
                currentNumber = 0;
            }
        }

        int result = 0;

        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};



//2nd Approach

class Solution {
public:
    int calculate(string s) {

        int length = s.length();
        if (length == 0) return 0;

        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';

        for (int i = 0; i < length; i++) {

            char currentChar = s[i];

            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {

                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }

                sign = currentChar;
                currentNumber = 0;
                
            }
        }
        result += lastNumber;
        return result;  
    }
};
