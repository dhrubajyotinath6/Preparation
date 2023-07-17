class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size(), m = needle.size();
        
        // n = 8, m = 2 -> it means we have to check till second last
        // 0  1   2  3  4  5  6  7 -> till 6  -> n - m = 6
        for(int windowStart = 0; windowStart <= n - m; windowStart++){
            
            for(int i = 0; i < m; i++){
                if(needle[i] != haystack[windowStart + i]){
                    break;
                }
                
                if(i == m - 1){
                    return windowStart;
                }
            }
        }
        
        return -1;
    }
};

//check KMP and RABIN KARP