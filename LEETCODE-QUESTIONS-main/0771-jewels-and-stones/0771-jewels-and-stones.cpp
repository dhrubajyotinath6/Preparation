class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        set<char> s;
        for(auto &jewel : jewels){
            s.insert(jewel);
        }
        
        int ans = 0;
        
        for(auto &stone : stones){
            if(s.find(stone) != s.end()) ans++;
        }
        
        return ans;
    }
};