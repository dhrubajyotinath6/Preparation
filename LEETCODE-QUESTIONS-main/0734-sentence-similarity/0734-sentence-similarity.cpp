/*
Notice that a word is always similar to itself, also notice that the similarity relation is not transitive. 
For example, if the words a and b are similar, and the words b and c are similar, a and c are not necessarily similar.


---------

greek -> ok
greek -> maam

greek -> ok, maam
ok    -> greek
maam  -> greek

---------

ok    -> greek
maam  -> greek

ok    -> greek
greek -> ok, maam
maam  -> greek

-------------------------
*/

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        if(sentence1.size() != sentence2.size()){
            return false;
        }
        
        unordered_map<string, unordered_set<string>> wordToSimilarWords;
        
        for(auto& pair : similarPairs){
            wordToSimilarWords[pair[0]].insert(pair[1]);
            wordToSimilarWords[pair[1]].insert(pair[0]);
        }
        
        
        for(int i = 0; i < sentence1.size(); i++){
            
            if(sentence1[i] == sentence2[i]){
                continue;
            }
            
            if (wordToSimilarWords[sentence1[i]].count(sentence2[i])) {
                continue;
            }
            
            return false;
        }
        
        return true;
    }
};



















