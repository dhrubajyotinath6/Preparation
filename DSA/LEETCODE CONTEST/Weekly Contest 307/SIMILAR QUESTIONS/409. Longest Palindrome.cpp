/*
//https://leetcode.com/problems/longest-palindrome/discuss/791646/C%2B%2BPythonJava-It-is-only-easy-when-you-think-really-hard-to-spot-the-built-in-nature

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

*/

/*
https://leetcode.com/problems/longest-palindrome/discuss/791646/C%2B%2BPythonJava-It-is-only-easy-when-you-think-really-hard-to-spot-the-built-in-nature


class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> mpp;

        for(auto chr : s){
            mpp[chr]++;
        }

        int ans = 0;
        int single = 0;

        for(int j = 0; j < s.size(); j++){

            char ch = s[j];

            while(mpp[ch] > 1){

                ans += 2;

                mpp[ch] -= 2;
            }

            if(mpp[ch] == 1 && single == 0 ) single = 1;

        }

        // cout << single << endl;

        return (ans + single);

    }
};
*/

class Solution
{
public:
    int longestPalindrome(string s)
    {

        vector<int> mpp(128, 0);

        for (auto ch : s)
        {
            mpp[ch - '0']++;
        }

        int ans = 0;
        bool flag = false;

        for (auto i : mpp)
        {

            // even
            if (i % 2 == 0)
            {
                ans += i;
            }

            else if (i % 2 == 1)
            {
                ans += i - 1;
                flag = true;
            }
        }

        if (flag)
            return ans + 1;
        else
            return ans;
    }
};
