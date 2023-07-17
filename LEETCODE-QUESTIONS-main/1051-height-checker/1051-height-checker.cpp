//https://leetcode.com/problems/height-checker/discuss/369999/Help-you-to-understand-this-question-and-also-the-optimal-O(N)-solution!  -- try this with counting sort

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> sorted = heights;
        sort(begin(sorted), end(sorted));
        
        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            if(sorted[i] != heights[i]) ans++;
        }
        
        return ans;
    }
};