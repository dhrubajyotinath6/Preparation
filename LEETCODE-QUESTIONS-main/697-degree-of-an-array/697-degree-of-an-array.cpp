//https://leetcode.com/problems/degree-of-an-array/discuss/124317/JavaC%2B%2BPython-One-Pass-Solution

class Solution {
public:
    
    int findShortestSubArray(vector<int>& A) {
        
        unordered_map<int, int> counter, first;
        
        int res = 0, degree = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            
            if (first.count(A[i]) == 0) first[A[i]] = i;
            
            if (++counter[A[i]] > degree) {
                degree = counter[A[i]];
                res = i - first[A[i]] + 1;
            } else if (counter[A[i]] == degree)
                res = min(res, i - first[A[i]] + 1);
        }
        return res;
    }
};