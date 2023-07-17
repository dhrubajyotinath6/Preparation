class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string,int> map;
        for(int i = 0; i < list1.size(); i++){
            map[list1[i]] = i;
        }
        
        vector<string> ans;
        int mini = INT_MAX;
        
        for(int i = 0; i < list2.size(); i++){
            
            int sum = 0;
            
            if(map.find(list2[i]) != map.end()){
                sum = i + map[list2[i]];
                
                if(sum < mini){
                    ans.clear();
                    ans.push_back(list2[i]);
                    mini = sum;
                }else if(sum == mini){
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
    }
};