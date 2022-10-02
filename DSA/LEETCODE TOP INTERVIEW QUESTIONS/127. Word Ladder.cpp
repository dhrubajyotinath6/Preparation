//https://leetcode.com/problems/word-ladder/solution/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence 
from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

 
 class Solution {
    
    vector<string> n(string word){
        
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> q;
        set<string> hashSet(wordList.begin(),wordList.end());
        
        words.remove(beginWord);
        q.push(beginWord);
        
        int level = 0;
        
        while(!q.empty()){
            int size = queue.size();
            level++;
            
            for(int i = 0; i < size; i++){
                string currentWord = q.front();
                q.pop();
                
                if(currentWord == endWord) return level;
                
                vector<string> neighbors = n(currentWord);
                
                for(auto &neigh : neighbors){
                    if(words.count(neigh)){
                        words.remove(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
        return 0;
    }
};
