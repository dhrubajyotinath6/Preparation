//https://www.geeksforgeeks.org/maximum-sum-sub-arrays-two-different-arrays/

Given two arrays of positive integers. Select two sub-arrays of equal size from each array and calculate maximum possible OR sum of the two sub-arrays. 

Note: Let f(x, l, r) is the OR sum of all the elements in the range [l, r] in array x. 

Examples : 

Input : A[] = {1, 2, 4, 3, 2}
        B[] = {2, 3, 3, 12, 1}
Output : 22
Explanation: Here, one way to get maximum
sum is to select sub-array [l = 2, r = 4]
f(A, 2, 4) = 2|4|3 = 7
f(B, 2, 4) = 3|3|12 = 15
So, f(A, 2, 4) + f(B, 2, 4) = 7 + 15 = 22.
This sum can be achieved in many other ways.

Input : A[] = {1, 2, 2}
        B[] = {2, 1, 3}
Output : 6


// function to find maximum OR sum
void MaximumSum(int a[], int b[], int n)
{
    int sum1 = 0, sum2 = 0;
     
    // OR sum of all the elements
    // in both arrays
    for (int i = 0; i < n; i++) {
        sum1 |= a[i];
        sum2 |= b[i];
    }
    cout << sum1 + sum2 << endl;
}

