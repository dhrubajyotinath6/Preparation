//https://www.geeksforgeeks.org/count-subarrays-whose-maximum-element-greater-k/

Given an array of n elements and an integer k. The task is to find the count of the 
subarray which has a maximum element greater than K.

Examples : 

Input : arr[] = {1, 2, 3} and k = 2.
Output : 3
All the possible subarrays of arr[] are 
{ 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, 
{ 1, 2, 3 }.
Their maximum elements are 1, 2, 3, 2, 3, 3.
There are only 3 maximum elements > 2.


Approach 2
// C++ program to count number of subarrays 
// whose maximum element is greater than K. 
#include <bits/stdc++.h> 
using namespace std; 

long long countSubarray(int arr[], int n, int k) 
{ 
	long long ans = 0 ; 
		int prev = - 1; //prev for keeping track of index of previous element > k; 
		for(int i = 0 ; i < n ; i++ ) { 
		if ( arr [ i ] > k ) { 
			ans += n - i ; //subarrays starting at index i. 
			ans += i - prev - 1 ; //subarrays ending at index i but starting after prev. 
			ans += ( n - i - 1 ) * 1LL * ( i - prev - 1 ) ; //subarrays having index i element in between. 
			prev = i; // updating prev 
		} 
		} 
		return ans; 
} 

// Driven Program 
int main() 
{ 
	int arr[] = { 4, 5, 1, 2, 3 }; 
	int k = 2; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << countSubarray(arr, n, k); 
	return 0; 
} 

