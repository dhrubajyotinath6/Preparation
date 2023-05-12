//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> queue;
        set<string> words;
        
        for(string s:wordList){
            words.insert(s);
        }
        
        words.erase(beginWord);
        queue.push(beginWord);
        
        int level = 0;
        
        while(!queue.empty()){
            int size = queue.size();
            level++;
            
            for(int i = 0; i < size; i++){
                string currWord = queue.front();
                queue.pop();
                
                if(currWord == endWord) return level;
                
                vector<string> neighbors = f(currWord);
                for(auto neigh : neighbors){
                    if(words.find(neigh) != words.end()){
                        words.erase(neigh);
                        queue.push(neigh);
                    }
                }
            }
            
        }
        return 0;
        
    }
    
    vector<string> f(string word){
        vector<string> res;
        
        for(int i = 0; i < word.size(); i++){            
            string temp = word;            
            for(char c = 'a'; c <= 'z'; c++){
                //we donot hv to worry for making 'hot' from 'hot'
                //bcoz when we push at queue we deleted the 'hot' word
                temp[i] = c;
                res.push_back(temp);
            }
        }
        return res;
    }
};