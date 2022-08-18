/*
KMP ALGO

https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP

*/

/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().



Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

/*
1.
    Input
    "a"
    "a"

    Output
    -1

    Expected
    0
*/

/*

VERY BEAUTIFUL TEST CASE
2.
Input
"mississippi"
"issip"

Output
-1

Expected
4


class Solution {  -> thats why it doesnot work
public:
    int strStr(string haystack, string needle) {

        if(needle == ""){
            return 0;
        }

        if(needle.size() > haystack.size()) return -1;

        int j = 0;
        int startIndex = -1;

        for(int i = 0; i < haystack.size(); i++){

            if(haystack[i] == needle[j]){

                if(j == 0){
                    startIndex = i;
                }

                if(j == needle.size()-1 ){ // why not else if check upper test case
                    break;
                }

                j++;
            }
            else if(haystack[i] != needle[j]){
                j = 0;
            }
        }

        return j == needle.size() - 1 ? startIndex : -1;

    }
};
*/