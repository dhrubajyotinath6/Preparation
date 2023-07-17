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