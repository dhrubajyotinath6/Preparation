class Solution {
    int solution(vector<string>& words, unordered_map<char,int> freq, vector<int>& score, int ind){
        
        //base case
        if(ind == words.size()) return 0;
        
        //word not included
        int score_no = 0 + solution(words, freq, score, ind + 1);
        
        //word to include
        int score_word = 0;
        string word = words[ind];
        bool flag = true;
        
        for(int i = 0; i < word.length(); i++){
            
            char ch = word[i];
            
            
            if(freq[ch] == 0) flag = false; 
             
            freq[ch]--;   
            
            score_word += score[ch - 'a'];
        }
        
        int score_yes = 0;
        
        if(flag) score_yes = score_word + solution(words, freq, score, ind + 1);
        
        for(int i = 0; i < word.length(); i++){

            char ch = word[i];
            freq[ch]++;
        }
        
        return max(score_no, score_yes);
        
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        unordered_map<char,int> freq;
        for(int i = 0; i < letters.size(); i++){
            freq[letters[i]]++;
        }
        
        int res = solution(words, freq, score, 0);
        return res;
    }
};