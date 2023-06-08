//https://leetcode.com/problems/word-ladder/

/*
A transformation sequence from word beginWord to word endWord using a dictionary 
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, 
return the number of words in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.

 


Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", 
which is 5 words long.


Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence


*/

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


//by striver 
//https://takeuforward.org/graph/word-ladder-i-g-29/
#include <bits/stdc++.h>
using namespace std;
 
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
};
 
int main()
{
 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
    return 0;
}