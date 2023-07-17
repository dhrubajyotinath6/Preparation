class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        set<int> s;
        for(auto &candy : candyType){
            s.insert(candy);
        }
        
        return min(s.size(), candyType.size()/2);
    }
};