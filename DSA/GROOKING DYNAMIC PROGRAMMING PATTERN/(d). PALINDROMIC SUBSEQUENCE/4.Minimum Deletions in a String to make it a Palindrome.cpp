/*
Given a string, find the minimum number of characters that we can remove to make it a palindrome.

Example 1:

Input: "abdbca"
Output: 1
Explanation: By removing "c", we get a palindrome "abdba".



Example 2:

Input: = "cddpd"
Output: 2
Explanation: Deleting "cp", we get a palindrome "ddd".


Example 3:

Input: = "pqr"
Output: 2
Explanation: We have to remove any two characters to get a palindrome, e.g. if we
remove "pq", we get palindrome "r".

*/

/*
This problem can be easily converted to the Longest Palindromic Subsequence (LPS) problem.
 We can use the fact that LPS is the best subsequence we can have,
 so any character that is not part of LPS must be removed.
 Please note that it is ‘Longest Palindromic SubSequence’ and not ‘Longest Palindrome Substring’.

So, our solution for a given string ‘st’ will be:

  Minimum_deletions_to_make_palindrome = Length(st) - LPS(st)


*/