class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        
        int ans = 0, i = 0, j = 0;
        
        while(i < g.size() && j < s.size()){
            
            if(s[j] >= g[i]){
                ans++;
                i++, j++;
            }
            else{
                //s[i] < g[i]
                j++;
            }
        }
        
      return ans;  
    }
};