bool cmp(vector<int> a, vector<int> b){
    if(a[1] < b[1]) return true;
    return false;
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        
        int count = 1;
        int limit = pairs[0][1];
        
        for(int i = 1; i < n; i++){
            if(limit < pairs[i][0]){
                limit = pairs[i][1];
                count++;
            }
        }
        
        return count;
    }
};

//https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/225801/Proof-of-the-greedy-solution


