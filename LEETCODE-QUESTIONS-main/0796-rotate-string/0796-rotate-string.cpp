/*
All rotations of A are contained in A+A. Thus, we can simply 
check whether B is a substring of A+A. We also need to check 
A.length == B.length, otherwise we will fail cases like A = 
"a", B = "aa".


SOLVE THIS PROBLEM USING KMP -- VERY IMP
https://leetcode.com/problems/rotate-string/solution/ --CHECK APPROACH 4

https://leetcode.com/problems/rotate-string/discuss/678931/Best-Solution-for-an-Interview-Java-Thoughts-and-takeaways   -- VERY IMP READ THIS

https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/

*/

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};