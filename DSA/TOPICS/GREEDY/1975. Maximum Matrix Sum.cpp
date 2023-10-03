

You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements.

 Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [
                 [1,-1],
                 [-1,1]
                 ]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
Example 2:


Input: matrix = [
                 [1,2,3],
                 [-1,-2,-3],
                 [1,2,3]
                 ]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.




Recognize that if there is an even amount of negative numbers, 
you can eliminate all the negatives signs in the following fashion:

If there is a pair of adjacent negative numbers, just remove both negative signs

If the remaining negative numbers are separated from each other, just swap their negative signs 
with the adjacent positive number until they are adjacent to each other, 
and then you can remove 2 negative signs at a time

If there is an odd amount of negative sign, there will be a negative sign in the end, 
and we can move that negative sign to the smallest number in the matrix (by swapping as above)

So, if the number of negative signs is even, the answer is the sum of the absolute value of all elements. 
If it is odd, we will have to minus 2 times the number with smallest absolute value 
(for we have to change + sign to -) to get the answer:


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        long long sum = 0;
        int mini = INT_MAX;
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
                
                if(matrix[i][j] < 0) cnt++;
            }                
         }
        
        if(cnt % 2 == 0) return sum;
        return sum - 2*mini;               
    }
};

