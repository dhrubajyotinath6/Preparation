class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int windowStart = 0, ans = 0;
        unordered_map<char,int> mpp;
        
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
            
            char ch = s[windowEnd];
            
            if(mpp.find(ch) != mpp.end()){
                windowStart = max(windowStart, mpp[ch] + 1);
            }
            
            mpp[ch] = windowEnd;
            
           ans = max(ans, windowEnd - windowStart + 1);
          
        }
        
        return ans;
    }
};

//abccab