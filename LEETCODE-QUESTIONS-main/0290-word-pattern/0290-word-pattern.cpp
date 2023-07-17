class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        
        vector<string> str;
        // word variable to store word in the string s
        string word;
        // making a string stream
        stringstream iss(s);
       // Push each word in vector
        while (iss >> word)
            str.push_back(word);
        
        
        if(str.size() != pattern.size()) return false;
        
        for(int i = 0; i < str.size(); i++){
            char ch = pattern[i];
            string word = str[i];
            
            if(map1.find(ch) == map1.end()){
                /*
                a - dog
                b - dog
                */
                if(map2.find(word) != map2.end()) return false;
                else{
                    map1[ch] = word;
                    map2[word] = ch;
                }
            }
            else{
                string mappedWord  = map1[ch];
                /*
                a - cat
                a - dog
                */
                if(mappedWord != word) return false;
            }
        }
        return true;
    }
};