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