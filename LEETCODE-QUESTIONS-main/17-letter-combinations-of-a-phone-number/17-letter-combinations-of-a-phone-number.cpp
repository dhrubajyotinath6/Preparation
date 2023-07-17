/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/1148252/Short-and-Easy-Solutions-or-Multiple-Approaches-Explained-or-Beats-100
*/
class Solution {
public:
    
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;    
    vector<string> letterCombinations(string digits) {
        
	if(digits == "") return ans;         
	helper(digits, 0, "");              
	return ans;

}

void helper(string &digits, int i, string combi){
    
	if(i == size(digits))  
		ans.push_back(move(combi));    
    
	else
		for(auto c : mappings[digits[i] - '2']) 
			helper(digits, i + 1, combi + c);
}
};