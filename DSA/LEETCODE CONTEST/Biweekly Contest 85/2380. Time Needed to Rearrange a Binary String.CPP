/*
https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/

You are given a binary string s. In one second, all occurrences of "01" are simultaneously replaced with "10". This process repeats until no occurrences of "01" exist.

Return the number of seconds needed to complete this process.



Example 1:

Input: s = "0110101"
Output: 4
Explanation:
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.
Example 2:

Input: s = "11100"
Output: 0
Explanation:
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.


Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
*/

// O(n) square
/*
class Solution {

public:
    int secondsToRemoveOccurrences(string binaryInput) {

        int n = binaryInput.size();
        int ans = 0;

        while(1){

            bool found = false;

            for(int i = 0; i < n-1; ){

                if(binaryInput[i] == '0' && binaryInput[i+1] == '1'){

                    binaryInput[i] == '1';
                    binaryInput[i+1] == '0';

                    found = true;
                    i+= 2;
                }
                else {
                    i++;
                }

            }

            if(!found) break;
            else ans++;

        }

        return ans;
    }

};

*/
/*
https://github.com/LachezarTsK/Time-Needed-to-Rearrange-a-Binary-String/blob/main/Solution.cpp

https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/discuss/2454262/DP-vs.-Brute-Force

*/

class Solution
{

public:
    int secondsToRemoveOccurrences(string binaryInput)
    {

        int numberOfZeros = 0;
        int seconds = 0;

        for (const auto &digit : binaryInput)
        {
            if (digit == '0')
            {
                ++numberOfZeros;
            }
            else if (numberOfZeros > 0)
            {
                seconds = max(seconds + 1, numberOfZeros);
            }
        }
        return seconds;
    }
};
