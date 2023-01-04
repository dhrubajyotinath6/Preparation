/*
https://takeuforward.org/data-structure/subarray-with-given-sum/

Example 1:
Input:
 arr = {1, 7, 3, 9}, k = 10

Output: 7 3
Explanation:
 Of all the subarrays, 7 and 3 sums to 10.



Example 2:
Input: arr = {2,1,3,4,5,6}, k = 10
Output: 2 1 3 4
Explanation: Of all the subarrays, 2, 1, 3 and 4 sums to 10
*/

#include<bits/stdc++.h>

using namespace std;

void subArrayWithGivenSum(vector<int> &arr, int K){

        int windowSum = 0;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++){

            windowSum += arr[windowEnd];

            while(windowSum > K){
                windowSum -= arr[windowStart];
                windowStart++;
            } 
            
            if(windowSum == K){

                for(int i = windowStart; i <= windowEnd; i++){
                    cout << i << " ";
                }
                cout << endl;
            }
           
        }

       return; 
}

int main(){


    vector<int> arr {1, 9, 3, 7};  
    int k = 10;    
    subArrayWithGivenSum(arr, k);

    return 0;
}

/*
vector<int> arr {1, 9, 3, 7}; int k = 10;  
0 1
2 3
*/