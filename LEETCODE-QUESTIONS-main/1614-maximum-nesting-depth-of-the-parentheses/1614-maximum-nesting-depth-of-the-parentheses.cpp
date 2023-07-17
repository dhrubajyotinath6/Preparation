class Solution {
public:
    int maxDepth(string s) {
        
        int maxi = 0, count = 0;
        
        for(auto &ch : s){
            
            if(ch == '(') count++;
            if(ch == ')') count--;
            
            maxi = max(maxi, count);
        }
        return maxi;
    }
};