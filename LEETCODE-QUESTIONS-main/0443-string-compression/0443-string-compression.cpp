class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0, j = 0;
        
        while(i < chars.size()){
            int grpLength = 1;
            
            while(i + grpLength < chars.size() && chars[i+grpLength] == chars[i]){
                grpLength++;
            }
            
            chars[j++] = chars[i];
            
            if(grpLength > 1){
                for(char c : to_string(grpLength)){
                    chars[j++] = c;
                }
            }
            
            i += grpLength;
        }
        
     return j;
    }
};