/*
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1;
        for(auto &s : word1){
            str1 += s;
        }
        
        string str2;
        for(auto &s : word2){
            str2 += s;
        }
        
        return str1 == str2;
    }
};
*/


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int word1Pointer = 0, word2Pointer = 0;
        
        int string1Pointer = 0, string2Pointer = 0;
        
        while(word1Pointer < word1.size() && word2Pointer < word2.size()){
            
            if (word1[word1Pointer][string1Pointer++] != word2[word2Pointer][string2Pointer++]) {
                return false;
            }
            
                        // If the string pointer reaches the end of string in the list word1, 
            // Move to the next string in the list and, reset the string pointer to 0.
            if (string1Pointer == word1[word1Pointer].size()) {
                word1Pointer++;
                string1Pointer = 0;
            }
            // If the string pointer reaches the end of string in the list word2, 
            // Move to the next string in the list and, reset the string pointer to 0.
            if (string2Pointer == word2[word2Pointer].size()) {
                word2Pointer++;
                string2Pointer = 0;
            }
            
            
        }
        
        return word1Pointer == word1.size() && word2Pointer == word2.size();
    }
};