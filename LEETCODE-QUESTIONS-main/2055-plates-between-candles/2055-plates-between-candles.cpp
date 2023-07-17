//https://leetcode.com/problems/plates-between-candles/discuss/1604537/2-C%2B%2B-Solutions-or-Binary-Search-or-Prefix-Sum   --IMP

/*
The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last)
which has a value not less than val. T
his means that the function returns an iterator pointing to the next smallest number just greater than or equal to that numbe

Input: 10 20 30 40 50
Output: lower_bound for element 30 at index 2

Input: 10 20 30 40 50
Output: lower_bound for element 35 at index 3

Input: 10 20 30 40 50
Output: lower_bound for element 55 at index 5 (Basically, 55 is not present, so it returns end() iterator)

Input: 10 20 30 30 30 40 50
Output: lower_bound for element 30 at index 2
*/


Solution 1: Binary Search
Store index of all candles in a vector.
For each query find index of first and last candle in the given range using binary search.
Number of plates between candles will be number of elements between first and last candle minus number of candles between them.

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candlesIndex;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '|')
                candlesIndex.push_back(i);
        }
        
        vector<int> ans;
        for(auto q : queries){
            int firstCandleIndex = lower_bound(candlesIndex.begin() , candlesIndex.end() , q[0]) - candlesIndex.begin();
            int lastCandleIndex = upper_bound(candlesIndex.begin() , candlesIndex.end() , q[1]) - candlesIndex.begin() - 1;
            
            if(lastCandleIndex <= firstCandleIndex){
                ans.push_back(0);
                continue;
            }
                
            
            int tempAns = candlesIndex[lastCandleIndex] - candlesIndex[firstCandleIndex] - (lastCandleIndex - firstCandleIndex);
            
            ans.push_back(tempAns);
        }
        return ans;
    }
};
