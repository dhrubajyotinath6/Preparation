class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        int n = s.size();
        vector<int> ans(n, INT_MAX);
        
        int prev = -1;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c) prev = i;
            if(prev != -1) ans[i] = i - prev;
        }
        
        prev = n;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == c) prev = i;
            
            if(prev != n) ans[i] = min(ans[i], prev - i);
        }
        
        return ans;
    }
};