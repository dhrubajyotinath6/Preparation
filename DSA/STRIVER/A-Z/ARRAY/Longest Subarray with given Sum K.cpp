#include<bits/stdc++.h>

using namespace std;

int longestSubArrWithSumK(vector<int> &arr, int K){

        int windowSum = 0, maxLength = INT_MIN;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++){

            windowSum += arr[windowEnd];
            
            while(windowSum > K){
                windowSum -= arr[windowStart];
                windowStart++;
            }

            if(windowSum == K){
                maxLength = max(maxLength, windowEnd - windowStart + 1);
            }
        }

       return maxLength; 
}

int main(){

    /*
    7,1,6,0  ; k = 7 => 3
    10, 5, 2, 7, 1, 9 ; k = 15  => 4
    arr = {2,3,5,1,9}, k = 10 => 3
    
    */
    vector<int> arr {2, 3, 5, 1, 9};  // 3
    int k = 10;    
    cout << longestSubArrWithSumK(arr, k) << endl;

    return 0;
}