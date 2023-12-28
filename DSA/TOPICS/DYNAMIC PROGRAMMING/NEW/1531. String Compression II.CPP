Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

 

Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
Example 2:

Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
 

Constraints:

1 <= s.length <= 100
0 <= k <= s.length
s contains only lowercase English letters.



/*
1. https://leetcode.com/problems/string-compression-ii/discuss/756022/C%2B%2B-Top-Down-DP-with-explanation-64ms-short-and-clear

2. https://leetcode.com/problems/string-compression-ii/discuss/2704470/LeetCode-The-Hard-Way-Explained-Line-By-Line

3. https://leetcode.com/problems/string-compression-ii/discuss/757506/Detailed-Explanation-Two-ways-of-DP-from-33-to-100

*/

/*
Input
"llllllllllttttttttt"
1
Output
5
Expected
4

l - 10
t - 9



*/
/*
class Solution {
    
public:
  struct valueCompare {
    bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return y.second < x.second;
    }
  };
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        if(k == s.size()) return 0;
        
        unordered_map<char, int>characterFrequencyMap;
        for(auto& ch : s){
            characterFrequencyMap[ch]++;
        }
        
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> minHeap;

        // add all characters to the max heap
        for (auto entry : characterFrequencyMap) {
          minHeap.push(entry);
        }
        
        
        while(!minHeap.empty() && k > 0){
            auto entry = minHeap.top();
            minHeap.pop();
            
            if(entry.second <= k){
                k -= entry.second;
            }else{
               
                // entry.second -= k;
                // k = 0;
                minHeap.push(entry);
            }
        }
        
        int len = 0;
        
        while(!minHeap.empty()){
            auto entry = minHeap.top();
            minHeap.pop();
            
           int x = entry.second;
           if( x == 1) len += 1;
           else if(x <= 9 && x > 1) len += 2;
           else if( x >= 10 && x <= 99) len += 3;
           else if( x == 100) len += 4;
        }
        
        return len;
        
        
    }
};

*/

/*
class Solution{
   
public:
    vector<vector<vector<vector<int>>>> dp;

    int calcLen(int len) {
        if (len == 0) return 0;
        else if (len == 1) return 1;
        else if (len < 10) return 2;
        else if (len < 100) return 3;
        else return 4;
    }

    int solve(int i, int ch, int len, int k, string str) {
        
        if (i == str.length()) return calcLen(len);
        
        if (dp[i][ch][len][k] == INT_MAX) {
            
            int c = str[i] - 'a';
            
            if (k > 0) dp[i][ch][len][k] = solve(i + 1, ch, len, k - 1, str);
            if (c == ch) dp[i][ch][len][k] = min(dp[i][ch][len][k], solve(i + 1, ch, len + 1, k, str));
            else dp[i][ch][len][k] = min(dp[i][ch][len][k], calcLen(len) + solve(i + 1, c, 1, k, str));
            
        }
        return dp[i][ch][len][k];
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.length();
        dp.resize(n, vector<vector<vector<int>>>(26, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MAX))));

        return solve(0, 0, 0, k, s);
    }
    
    
};
*/


class Solution
{
    int encodedLen(int len)
    {
        if (len <= 1) return len;
        else if (len < 10) return 2;
        else if (len < 100) return 3;
        else return 4;
    }

    public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.length();
        vector<vector<long>> dp(n+1,vector<long>(k+1,INT_MAX));
        dp[0][0]=0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j > 0) 
                    dp[i][j] = dp[i - 1][j - 1];
                int removed = 0, count = 0;
                for (int p = i; p > 0; p--)
                {
                    if (s[p-1] == s[i-1]) 
                        count++;
                    else if (++removed > j)
                        break;
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - removed] + encodedLen(count));
                }
            }
        }
        return dp[n][k];
    }
};