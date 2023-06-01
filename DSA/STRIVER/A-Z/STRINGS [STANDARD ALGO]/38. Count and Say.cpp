//https://leetcode.com/problems/count-and-say/

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the minimal number of substrings 
such that each substring contains exactly one unique digit. 
Then for each substring, say the number of digits, then say the digit. 
Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"


/*
At the beginning, I got confusions about what is the nth sequence.  
The following are sequence from n=1 to n=10:

 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.    13211311123113112211
 
From the examples you can see, 
the (i+1)th sequence is the "count and say" of the ith sequence!

*/

class Solution {
public:
    string countAndSay(int n) {
        
        string currString = "1";
        
        for(int i = 2; i <= n; i++){
            
        /*
            111221
            312211
        */    
            string nextString;
            int j = 0;
            
            while(j < currString.size()){
                char currChar = currString[j];
                
                // cout << currChar << endl;
                
                int k = 0;
                while(currChar == currString[j]){
                    k++;
                    j++;
                }
                // cout << k << " " << j << endl << endl;
                nextString += to_string(k) + currString[j-1];
            }
            
            // cout << nextString << endl;
            
            currString = nextString;
            
            
        }
        
        return currString;
    }
};