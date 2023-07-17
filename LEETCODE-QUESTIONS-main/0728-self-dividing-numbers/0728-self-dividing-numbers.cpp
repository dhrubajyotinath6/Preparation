class Solution {
    
public:
    bool selfDividing(int n){
        
        int x = n;
        while(x > 0){
            int d = x%10;
            x /= 10;
            
            if(d == 0 || (n % d != 0)) return false;
        }
        return true;
    }
    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> ans;
        
        for(int i = left; i <= right; i++){
            if(selfDividing(i)) ans.push_back(i);
        }
        
        return ans;
    }
};