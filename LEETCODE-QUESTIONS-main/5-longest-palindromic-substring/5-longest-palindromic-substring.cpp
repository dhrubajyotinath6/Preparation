class Solution {
public:
    string longestPalindrome(string s) {
        
       vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
        
       for(int i = 0; i < s.length(); i++){
           dp[i][i] = true;
       }
        
       int maxi = 1, start = 0;
        
       for(int startIndex = s.length() - 1; startIndex >= 0; startIndex--){
           for(int endIndex = startIndex + 1; endIndex < s.length(); endIndex++){
               
               if(s[startIndex] == s[endIndex]){
                   if(endIndex - startIndex == 1 || dp[startIndex+1][endIndex-1] == true){
                       dp[startIndex][endIndex] = true;
                       
                       if(endIndex - startIndex + 1 > maxi){
                           maxi  = endIndex - startIndex + 1;
                           start = startIndex;
                       }
                       
                   }
               }
           }
       }
        
        return s.substr(start,maxi);
    }
};