class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        set<int> set;
        
        for(auto &i : arr){
            
            if( (set.find(2*i) != set.end()) || ((i%2 == 0) && set.find(i/2) != set.end()) ) {
                return true;
            }
            
            // if( (set.find(i << 1) != set.end()) || ((i%2 == 0) && set.find(i >> 1) != set.end()) ) {
            //     return true;
            // }  [-16,-13,8]  :)
            
            set.insert(i);
        }
        
	return false;
    }
};