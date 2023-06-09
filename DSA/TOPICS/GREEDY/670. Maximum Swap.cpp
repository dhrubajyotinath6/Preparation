//https://leetcode.com/problems/maximum-swap/

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.



Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

Constraints:

0 <= num <= 108

//https://leetcode.com/problems/maximum-swap/discuss/107073/C%2B%2B-one-pass-simple-and-fast-solution%3A-1-3ms-O(n)-time
class Solution {
public:
    int maximumSwap(int num) {
        
        string numStr = to_string(num);
        
        int maxIndex = -1, maxDigit = -1;
        int leftIndex = -1, rightIndex = -1;
        
        for(int i = numStr.size()-1; i >= 0; i--){
            
            // current digit is the largest by far
            if(numStr[i] > maxDigit){
                maxDigit = numStr[i];
                maxIndex = i;
                continue;
            }
            
            // best candidate for max swap if there is no more 
            // such situation on the left side
            if(numStr[i] < maxDigit){
                leftIndex = i;
                rightIndex = maxIndex;
            }           
            
        }
        
         // num is already in order
        if(leftIndex == -1) return num;
        
        swap(numStr[leftIndex], numStr[rightIndex]);
        
        return stoi(numStr);
        
    }
};

