/*
https://leetcode.com/problems/string-compression/discuss/175087/Java-Python
https://leetcode.com/problems/string-compression/discuss/323715/C%2B%2B-Concise-Two-Pointer-Solution

*/

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0;
        int count = 1;
        
        for(int j = 1; j <= chars.size(); j++, count++){
            
            //
            if(j == chars.size() || chars[j] != chars[j-1]){
                chars[i++] = chars[j-1];
                
                if(count >= 2){
                    for(char digit : to_string(count)){
                        chars[i++] = digit;
                    }
                }
            count = 0;
            }
            
            //
            
        }
        
    return i;
        
    }
};

/*
Wrong Answer
Runtime: 0 ms

Your input
["a","a","b","b","c","c","c"]

Output
["a","2","b","2"]

Expected
["a","2","b","2","c","3"]

*/
