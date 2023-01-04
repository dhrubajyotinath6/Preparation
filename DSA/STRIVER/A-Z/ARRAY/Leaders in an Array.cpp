/*
Problem Statement: Given an array, print all the elements which are leaders. 
A Leader is an element that is greater than all of the elements on its right side in the array.

Examples:

Example 1:
Input:
 arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]
Output:
 22 12 6
Explanation:
 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
*/


#include<iostream>

using namespace std;

void printLeadersOptimal(int arr[], int n) {
  //Choosing the right most element as the maximum
  int max = arr[n - 1];
  cout << arr[n - 1] << " ";

  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      cout << arr[i] << " ";
      max = arr[i];
    }

  cout << "\n";
}

int main() {

  int arr1[] = {4, 7, 1, 0};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << "The leaders of the first array are: " << endl;
  printLeadersOptimal(arr1, n1);

  int arr2[] = {10, 22, 12, 3, 0, 6};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << "The leaders of the second array are: " << endl;
  printLeadersOptimal(arr2, n2);

  return 0;
}