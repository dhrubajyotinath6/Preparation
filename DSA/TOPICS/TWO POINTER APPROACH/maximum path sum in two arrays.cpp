//https://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/

/*
ASKED TO ME IN  AMAZON

*/

Given two sorted arrays, the arrays may have some common elements. 
Find the sum of the maximum sum path to reach from the beginning of any array to the end of 
any of the two arrays. We can switch from one array to another array only at common elements. 

Note: The common elements do not have to be at the same indexes.

Examples: 

Input: ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
Explanation: 35 is sum of 1 + 5 + 7 + 10 + 12.
Start from the first element of ar2 which is 1, then move to 5, then 7.  From 7 switch to ar1 (as 7 is common) and traverse 10 and 12.

Input: ar1[] = {10, 12}, ar2 = {5, 7, 9}
Output: 22
Explanation: 22 is the sum of 10 and 12. 
Since there is no common element, take all elements from the array with more sum.

Input: ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}, ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122
Explanation: 122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34
Start from the first element of ar2 which is 1, then move to 5, then 7. From 7 switch to ar1 (as 7 is common), then traverse the remaining ar1.


int sum(vector<int> arr1, vector<int> arr2){

    int ans = 0, sum1 = 0, sum2 = 0;

    int i = 0, j = 0;

    int n = arr1.size(), m = arr2.size();

    while(i < n && j < m){

        if(arr1[i] < arr2[j]){
            sum1 += arr2[i++];
        }else if(arr1[i] > arr2[j]){
            sum2 += arr2[j++];
        }else{
            sum += max(sum1, sum2) + arr1[i];
            i++;
            j++;
            sum1 = 0, sum2 = 0;
        }
    }

    while(i < n){
         sum1 += arr2[i++];
    }

    while(j < m){
         sum2 += arr2[j++];
    }

     sum += max(sum1, sum2);
     return sum;
}

Time complexity: O(m+n)
Auxiliary Space: O(1)