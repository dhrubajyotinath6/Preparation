You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. 
However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form 
"011" which is not allowed due to having two consecutive buildings of the same type.

Return the number of valid ways to select 3 buildings.

 

Example 1:

Input: s = "001101"
Output: 6
Explanation: 
The following sets of indices selected are valid:
- [0,2,4] from "001101" forms "010"
- [0,3,4] from "001101" forms "010"
- [1,2,4] from "001101" forms "010"
- [1,3,4] from "001101" forms "010"
- [2,4,5] from "001101" forms "101"
- [3,4,5] from "001101" forms "101"
No other selection is valid. Thus, there are 6 total ways.


Example 2:

Input: s = "11100"
Output: 0
Explanation: It can be shown that there are no valid selections.
 

Constraints:

3 <= s.length <= 105
s[i] is either '0' or '1'.


//https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907026/Easy-understanding-C%2B%2B-code-with-comments

/*
https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907179/JavaPython-3-One-pass-T-O(n)-S-O(1)-codes-and-follow-up-w-brief-explanation-and-analysis.    --READ THIS TOO 
*/

//DP ALSO POSSIBLE CHECK THE DISCUSSION SECTION
/*
The possible sequences of selected buildings is either "101" or "010".

If the current building is '0',
then the number of sequences of pattern "101" will be the 
product of the number of occurances of building '1' before the current building 
to the number of occurances of building '1' after the current building 
and viceversa.

*/

/*
So, lets traverse the string and consider the current character as the centeral character of the combination.

    This means, if the current character is '0', then all we need to do it 
find the number of 1 before this 0 and number of 1 after this 0 
and multiply them to add them to the answer.
    We do the same for the central character as '1' and
count the number of 0 before and after this one.
*/


class Solution {
public:
    long long numberOfWays(string s) {
        
        long long count1=0, count0=0, ans=0;        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                count1++;
            else
                count0++;
        }
        
        long long count1SoFar = 0, count0SoFar = 0;             
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='1'){               // Counting the sequences of "010"
                ans+=(count0SoFar*count0);
                count1--;
                count1SoFar++;
            }
            else{                        // Counting the sequences of "101"
                ans+=(count1*count1SoFar);
                count0--;
                count0SoFar++;
            }
        }
        return ans;
    }
};
