/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

public: 
    void func(int ind, int sum,vector<int> &arr, int N, vector<int> &sumSubset) {
        if(ind == N) {
            sumSubset.push_back(sum); 
            return; 
        }
        
        // pick the element 
        func(ind + 1, sum + arr[ind], arr, N, sumSubset); 
        
        // Do-not pick the element
        func(ind + 1, sum, arr, N, sumSubset);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset; 
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
