Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
    void helper(vector<string> &res, string str, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(str);
            return;
        }
        if(left > 0) helper(res, str + "(", left - 1, right);
        if(right > left) helper(res, str + ")", left, right - 1);
    }
};




