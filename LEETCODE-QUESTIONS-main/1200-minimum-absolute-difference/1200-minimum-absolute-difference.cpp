//https://leetcode.com/problems/minimum-absolute-difference/solution/  -- very very imp

/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]

*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        // Initialize the auxiliary array `line`.
        // Keep a record of the minimum element and the maximum element.
        int minElement = *min_element(arr.begin(), arr.end());
        int maxElement = *max_element(arr.begin(), arr.end());
        
        int shift = -minElement;
        
        vector<uint8_t> line(maxElement - minElement + 1);
        vector<vector<int>> answer;
        
        // For each integer `num` in `arr`, we increment line[num + shift] by 1.
        for (const int& num : arr) {
            line[num + shift] = 1;
        }
        
        // Start from the index representing the minimum integer, initialize the 
        // absolute difference `min_pair_diff` as a huge value such as
        // `max_element - min_element` in order not to miss the absolute 
        // difference of the first pair.
        int minPairDiff = maxElement - minElement;
        int prev = 0;
        
        // Iterate over the array `line` and check if line[curr] 
        // holds the occurrence of an input integer.
        for (int curr = 1; curr <= maxElement + shift; ++curr) {
            // If line[curr] == 0, meaning there is no occurrence of the integer (curr - shift) 
            // held by this index, we will move on to the next index.
            if (line[curr] == 0) {
                continue;
            }
            
            // If the difference (curr - prev) equals `minPairDiff`, we add this pair 
            // {prev - shift, curr - shift} to the answer list. Otherwise, if the difference 
            // (curr - prev) is smaller than `minPairDiff`, we empty the answer list and add 
            // the pair {curr - shift, prev - shift} to the answre list and update the `minPairDiff`
            if (curr - prev == minPairDiff) {
                answer.push_back({prev - shift, curr - shift});
            } else if (curr - prev < minPairDiff) {
                minPairDiff = curr - prev;
                answer = {{prev - shift, curr - shift}};
            }        

            // Update prev as curr.
            prev = curr;
        }
        
        return answer;
    }
};