/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would 
always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/

/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/solution/  -> for solving using stack

*/


//https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/1229370/Short-and-Simple-Solution-w-Explanation-or-O(N)-and-O(1)-Space-Solutions
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
	int top = 0;
        
	for(auto& t : tokens){
        
		if(t == "+" || t == "-" || t == "*" || t == "/") {
            
			int op1 = stoi(tokens[--top]); 
			int op2 = stoi(tokens[--top]);
            
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;
			if(t == "/") op1 = op2 / op1;
			if(t == "*") op1 = op2 * op1;
            
			tokens[top++] = to_string(op1);
		}
		else tokens[top++] = t;
        
        //  for(auto &tok : tokens){
        //     cout << tok << " ";
        // }
        // cout << endl;
        
    }
	return stoi(tokens[0]);
}
};