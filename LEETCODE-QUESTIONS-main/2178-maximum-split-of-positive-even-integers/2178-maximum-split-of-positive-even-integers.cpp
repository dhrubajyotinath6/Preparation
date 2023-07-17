//https://leetcode.com/problems/maximum-split-of-positive-even-integers/discuss/1783586/C%2B%2B-Greedy-O(sqrt(N))-time-O(1)-space

/*
28 - 2 = 26
26 - 4 = 22
22 - 6 = 16
16 - 8 = 8  [here sum = 16 , i = 8., i + 2 = 10 and sum - i >= i + 2;(16 - 8 >= 10 ie 8 >= 10)doesnot hold]

*/
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum % 2) return {};
        
        vector<long long> ans;
        
        for(int i = 2; finalSum - i >= i + 2; i += 2){
            ans.push_back(i);
            finalSum -= i;
        }
        
        ans.push_back(finalSum);
        return ans;
    }
};