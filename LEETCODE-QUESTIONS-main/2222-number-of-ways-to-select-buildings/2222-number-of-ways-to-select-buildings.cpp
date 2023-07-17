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
