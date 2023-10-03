K-Messed Array Sort
Given an array of integers arr where each element is at most k places away from its sorted position, 
code an efficient function sortKMessedArray that sorts arr. 

For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted 
array will be located at either index 4, 5, 6, 7 or 8 in the input array.

Analyze the time and space complexities of your solution.

Example:

input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2

output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Constraints:

[time limit] 5000ms

[input] array.integer arr

1 ≤ arr.length ≤ 100
[input] integer k

0 ≤ k ≤ 20
[output] array.integer



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> sortKMessedArray( const vector<int>& arr, int k ){
 
}

int main() {
  
  
  vector<int> arr {6,1,4,11,2,0,3,7,10,5,8,9};
  int k = 6;
  
  arr =  sortKMessedArray(arr, k);
  
  for(auto &ch : arr){
    cout << ch << " ";
  }
  
  cout << endl;
  
  return 0;
}


ANS:

//https://www.geeksforgeeks.org/nearly-sorted-algorithm/

void sortK(int arr[], int n, int k)
{
 
    // Insert first k+1 items in a priority queue (or min
    // heap)
    //(A O(k) operation). We assume, k < n.
    // if size of array = k i.e k away from its target
    // position then
    int size;
    size = (n == k) ? k : k + 1;

    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + size);
 
    // i is index for remaining elements in arr[] and index
    // is target index of for current minimum element in
    // Min Heap 'pq'.
    int index = 0;
    // here even if size=k then n will be n=k,so i<n works
    // fine
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
}




