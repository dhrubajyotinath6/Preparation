/*
//https://leetcode.com/problems/first-bad-version/

You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if(n == 1) return 1;
        
        int low = 1, high = n;
        int ans;
        
        while(low <= high){
            
            //int mid = (low + high) >> 1;
            /*
            Line 11: Char 28: runtime error: signed integer overflow: 1063376696 + 2126753390 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:22:28

Last executed input
2126753390
1702766719
            */
            int mid = low + (high - low)/2;
            
            if(isBadVersion(mid)){
                ans = mid;
                high = mid -1;
            }
            
            else if(!isBadVersion(mid)){
                low = mid + 1;
            }
        }
        
        return ans;
    }
};