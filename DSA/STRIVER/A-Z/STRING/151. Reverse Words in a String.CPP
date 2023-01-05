/*
https://leetcode.com/problems/reverse-words-in-a-string/

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.


Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

//https://leetcode.com/problems/reverse-words-in-a-string/discuss/1531693/C%2B%2B-2-solutions-O(1)-space-Picture-explain-Clean-and-Concise
class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(), s.end());
        
        int l = 0, r = 0, i = 0, n = s.size();
        
        while (i < n) {
            
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        
        s.resize(r);
        
        return s;
    }
};