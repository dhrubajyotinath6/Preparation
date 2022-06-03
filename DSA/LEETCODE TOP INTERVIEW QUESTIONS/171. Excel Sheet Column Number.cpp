Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701


/*
https://leetcode.com/problems/excel-sheet-column-number/discuss/1790101/C%2B%2B-oror-4-Lines-oror-Easy-To-UnderStand-oror-0ms-oror-100
For s = "BCM" the final solution would be (2 x 26 x 26) + (3 x 26) + (13)
*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = 0;
        for(char c : columnTitle)
        {
			//d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a number like it's going to be C)

            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;

    }
};
