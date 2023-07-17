class Solution {
public:
    string capitalizeTitle(string title) {
        
        int j = 0;
        
        for(int i = 0; i <= title.size(); i++){
            
            //last word or white space
            if(i == title.size() || title[i] == ' '){
                
                /*
                If the length of the word is 1 or 2 letters, change all letters to lowercase.
                so we need to check if there is 3 letters or not
                a  b  c   ' '
                0  1  2   3
                */
                if(i - j > 2){
                    title[j] = toupper(title[j]);
                }
                
                //jump to first Letter of Next Word
                j = i + 1;
            }
            else{
                title[i] = tolower(title[i]);
            }
        }
        
        return title;
    }
};