/*
Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

*******************************************************************************************************************************
    NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
    for this problem, following are some good questions to ask :

    Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
    A : For the purpose of this question, YES
    Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
    A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
***********************************************************************************************************************************

Input Format
First argument is an array of digits.



Output Format
Return the array of digits after adding one.



Example Input
Input 1:

[1, 2, 3]


Example Output
Output 1:

[1, 2, 4]


Example Explanation
Explanation 1:

Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    
    //0 -> 1 but not 9->10 , 9 should be 9 0
    if(A.size() == 1 && A[0] == 0) {
        A[0]++;
        return A;
    } 
    
    //0567 -> 567, 0999->999 , 0 -> 0
    vector<int> ans;
    bool msb = false;
    
    for(int i : A){
        
        if(i == 0 && msb == false) continue;
        ans.push_back(i);
        msb = true;
    }

    
    for(int i = ans.size() - 1; i >= 0; i--){
        
        if(ans[i] != 9){
           ans[i]++;
           return ans; 
        } 
        else if(ans[i] == 9){
            ans[i] = 0;
        }     
      
    }
    
    // 999 -> 000    
    ans.push_back(0);
    ans[0] = 1;
    
    return ans;
}
