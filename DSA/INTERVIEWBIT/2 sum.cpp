/*

Problem Description

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    vector<int> ans;
    unordered_map<int,int> mpp;
    
    for(int i = 0; i < A.size(); i++){
        
        int target = B - A[i];
        
        if(mpp.find(target) != mpp.end()){
            ans.push_back(mpp[target] + 1); // this line should be written
            ans.push_back(i+1);             // before this line    
            return ans;
        }
        else if(mpp.find(A[i]) == mpp.end()){
            mpp[A[i]] = i;
        }
    }
    
    return ans;
}

/*
If multiple solutions exist, output the one where index2 is minimum. 
If there are multiple solutions with the minimum index2, 
choose the one with minimum index1 out of them.

Your submission failed for the following input
A : [ 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 ]
B : -3

The expected return value: 
4 8 
Your function returned the following: 
8 6 
*/
