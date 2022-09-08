/*
You are given a string allowed consisting of distinct characters and an array of strings words.
 A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.



Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

*/

// https://leetcode.com/problems/count-the-number-of-consistent-strings/discuss/969668/C%2B%2B-easy-solution    --FRIENDLY

// https://leetcode.com/problems/count-the-number-of-consistent-strings/discuss/969522/C%2B%2B-all_of --votrubac

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {

        int mpp[26] = {0}, ans = 0;

        for (auto &ch : allowed)
        {
            mpp[ch - 'a']++;
        }

        for (auto &word : words)
        {

            bool isConsistent = true;

            for (auto &ch : word)
            {

                if (mpp[ch - 'a'] == 0)
                {

                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent)
                ans++;
        }

        return ans;
    }
};


// this is easier
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        set<char> hashSet;
        
        for(auto ch : allowed){
            hashSet.insert(ch);
        }
        
        int ans = 0;
        
        for(auto word : words){
            
            bool isConsistent = true;
            
            for(auto ch : word){
                
                if(!hashSet.count(ch)){
                    isConsistent = false;
                }
            }
            
            if(isConsistent) ans++;
        }
        
        return ans;
    }
};