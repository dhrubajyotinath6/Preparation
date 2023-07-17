class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string>  code = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",      ".--", "-..-", "-.--", "--.."};
        
        unordered_map<string,int> mpp;
        
        for(auto word : words){
            
            string s = "";
            
            for(auto ch : word){
                
                int index = ch - 'a';
                
                s += code[index];
            }
            
            mpp[s]++;
        }
        
        int k = (int)mpp.size();
        
        return k;
        
    }
};