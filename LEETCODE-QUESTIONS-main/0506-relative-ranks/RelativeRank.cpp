/*
when we make a pair in priority_queue the sorting is done on the basis of first element of the pair right

https://leetcode.com/problems/relative-ranks/discuss/281681/C%2B%2B-Normalization   --READ THIS ALSO
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0; i < score.size(); i++){
            pq.push(make_pair(score[i],i));
        }
        
        vector<string> ans(score.size(), "");
        int count = 1;
        
        for(int i = 0; i < score.size(); i++){
            
            if(count == 1){
                ans[pq.top().second] = "Gold Medal";
            }
            else if(count == 2){
                ans[pq.top().second] = "Silver Medal";
            }
            else if(count == 3){
                ans[pq.top().second] = "Bronze Medal";
            }
            
            else{
                ans[pq.top().second] = to_string(count);
            }
            count++;
            pq.pop();
        }
        
        return ans;
    }
};
