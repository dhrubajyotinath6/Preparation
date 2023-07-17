class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int n = grades.size();
        int k = 0, total = 0;
        
        while((total + k + 1) <= n){
            
            k++;
            total += k;
        }
        
        return k;
    }
};