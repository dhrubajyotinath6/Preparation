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