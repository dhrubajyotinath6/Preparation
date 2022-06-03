Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 

Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]


// https://leetcode.com/problems/fizz-buzz/solution/
// check this too  https://leetcode.com/problems/fizz-buzz/discuss/149627/C%2B%2B-0ms-Solution-beats-100.00-without-if-else
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> result;
        
        for(int i = 1; i <= n; i++){
            
            bool divBy3 = (i % 3 == 0);
            bool divBy5 = (i % 5 == 0);
            
            string ans;
            
            if(divBy3) ans+= "Fizz";
            if(divBy5) ans+= "Buzz";
            
            if(!divBy3 && !divBy5) ans += to_string(i);
            
            result.push_back(ans);
            
        }
        
        return result;
    }
};

