/*
LEETCODE 

91. Decode Ways
70. Climbing Stairs
509. Fibonacci Number

*/

int Solution::uniquePaths(int A, int B) {
    
    int n = A + B - 2;
    int r = A - 1;
    
    double res = 1;
    
    for(int i = 1; i <= r; i++){
        
        res = res * (n-r+i)/i;
    }
   
   return (int)res; 
}
