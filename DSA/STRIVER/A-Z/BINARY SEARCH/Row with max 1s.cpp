//https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

//https://www.codingninjas.com/studio/problems/row-of-a-matrix-with-maximum-ones_982768

Sample Input 1 :
3 3
1  1  1
0  0  1
0  0  0
Sample Output 1 :
0
Explanation Of Input 1 :
The 0th row of the given matrix has the maximum number of ones.



Sample Input 2:
2 2
1  1
1  1
Sample Output 2:
0
Explaination Of Sample Output 2:
The 0th and 1st rows of the given matrix have the maximum number of ones, so we will output the lower index value.



Sample Input 3 :
2 1
0
0
Sample Output 3 :
-1
Explaination Of Sample Output 3:
No row is present where at-least one '1' is present. Hence the answer is -1.
Constraints :
1 ≤ N, M ≤ 100
0 ≤ ARR[i][j] ≤ 1

Where ARR[i][j] denotes the matrix elements.

Time Limit: 1 sec



class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxi1 = 0, maxiRow = -1;
	    
	    for(int i = 0; i < n; i++){
	        
	        ////////////////////
	        int count = 0, j = m-1;
	        
	        while(j >= 0 && arr[i][j] == 1){
	            count++;
	            j--;
	        }
	        
	        if(count > maxi1){
	            maxi1 = count;
	            maxiRow = i;
	        }
	        ///////////////
	        
	    }
	    
	    return maxiRow;
	}

};