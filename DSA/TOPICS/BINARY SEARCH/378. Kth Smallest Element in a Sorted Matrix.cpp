Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 

 /*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //maxHeap
        priority_queue<int> pq;
        
        int m = matrix.size(),  n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);
                
                if(pq.size() > k) pq.pop();
            }
        }
        
        return pq.top();
    }
};
*/

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise


class Solution {
    
public:
    int countsLessThanMid(vector<vector<int>>& matrix, int mid){
        
        int count = 0;
        int m = matrix.size(), n = matrix[0].size(); 
        
        int c = n-1;
        
        for(int r = 0; r < m; r++){
            while(c >= 0 && matrix[r][c] > mid) c--;
            
            count += (c+1);
        }
        
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int low = matrix[0][0],  high = matrix[m-1][n-1];
        int ans = -1;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(countsLessThanMid(matrix, mid)  >= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};











