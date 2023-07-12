//https://leetcode.com/problems/longest-string-chain/solution/  -> VERY IMP BOTH APPROACH

// https://leetcode.com/problems/longest-string-chain/solution/1309463


You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
without changing the order of the 
other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, 
where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. 
A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
  
  
 
  /*
class Solution {
    
public:
        int dfs(unordered_set<string> &wordsPresent, unordered_map<string,int> &dp, string currWord){
        
        if(dp.find(currWord) != dp.end()){
            return dp[currWord];
        }
        
        int maxLength = 1;
        
        for(int i = 0; i < currWord.length(); i++){
            
            string newWord = currWord.substr(0,i) + currWord.substr(i+1);
            
            if(wordsPresent.find(newWord) != wordsPresent.end()){
                int currLength = 1 + dfs(wordsPresent, dp, newWord);
                maxLength = max(maxLength, currLength);
            }
        }
        
        dp[currWord] = maxLength;
        
        return maxLength;
        
    }

public:
    
    int longestStrChain(vector<string>& words){
        
        unordered_map<string,int> dp;
        unordered_set<string> wordsPresent;
        
        for(auto word : words){
            wordsPresent.insert(word);
        }
        
        int ans = 0;
        
        for(auto word : words){
            ans = max(ans, dfs(wordsPresent, dp, word));
        }
        
        return ans;
    }
};

*/

class Solution {
    
public:
    
    int longestStrChain(vector<string>& words){
        
        unordered_map<string,int> dp;
        unordered_set<string> wordsPresent;
        
        sort(words.begin(),words.end(),[](const string &word1, const string &word2){
            return word1.size() < word2.size();
        });
        
        int ans = 1;
        
        for(auto word : words){
            int presentLength = 1;
            
            for(int i = 0; i < word.size(); i++){
                string pred = word.substr(0,i) + word.substr(i+1, word.size()+1);
                
                if(dp.find(pred) != dp.end()){
                    int prevLength = dp[pred];
                    presentLength = max(presentLength, prevLength + 1);
                }
            }
            
            dp[word] = presentLength;
            ans = max(ans, presentLength);
        }
            
        return ans;
    }
};
