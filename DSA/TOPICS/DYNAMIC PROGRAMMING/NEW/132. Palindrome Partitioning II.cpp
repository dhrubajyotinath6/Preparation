Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1


/*
class Solution {
   
public:
    bool isPalindrome(string &s, int i, int j){        
        while(i < j){            
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }        
        return true;
    }
    
public:
    int f(string s, int start, int end, vector<int> &dp){
        
        //base case
        if(dp[start] != -1) return dp[start];
        
        if(start > end) return dp[start] = 0;
        if(start == end) return dp[start] = 0;
        if(isPalindrome(s,start, end)) return dp[start] = 0;
        
        int cnt = INT_MAX;
        
        for(int i = start; i < end; i++){
            
            if(isPalindrome(s,start, i)){
                cnt = min(cnt, 1 + f(s, i + 1, end, dp));
            }
        }
        
        return dp[start] = cnt;
    }
    
public:
    int minCut(string s) {
        
        int n = s.size(); 
        
        vector<int> dp(n, -1);
        int ans = f(s, 0, n-1, dp);
        return ans;
    }
};
*/


//https://takeuforward.org/data-structure/palindrome-partitioning-ii-front-partition-dp-53/

class Solution {
   
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

   
public:
    int minCut(string str) {
        
        int n = str.size();
        // Create a DP array to store the minimum number of partitions.
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // Initialize the last element to 0.

        // Loop through the string in reverse order.
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            // Consider all possible substrings starting from the current index.
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, str)) {
                    // If the substring is a palindrome, calculate the cost and minimize it.
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        // Subtract 1 as it counts partitions, not cuts.
        return dp[0] - 1;
        
    }
};