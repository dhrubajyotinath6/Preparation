//https://leetcode.com/problems/count-sorted-vowel-strings/solution/   -- imp


Given an integer n, return the number of strings of length n 
that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as 
or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].


Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.



Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 

/*
//brute force
class Solution {
public:
    int countVowelStrings(int n) {
        return count(0,n,1);
    }
    
    int count(int index, int n, int vowels){
        
        if(index == n) return 1;
        
        int result = 0;
        
        for(int i = vowels; i <= 5; i++){
            result += count(1,n,i);
        }
        return result;
    }
};
*/

// ****************DP APPROACH NEEDS*********************


// MOST OPTIMAL APPROACH
/*
https://en.wikipedia.org/wiki/Combination#Number_of_combinations_with_repetition

*/

class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
