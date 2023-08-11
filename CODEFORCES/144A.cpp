#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    int maxi = INT_MIN, mini = INT_MAX, maxiIndex = -1, miniIndex = -1;

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i] > maxi){
            maxi = arr[i];
            maxiIndex = i;
        }

        if(arr[i] <= mini){
            mini = arr[i];
            miniIndex = i;
        }
    }

    int ans = (maxiIndex) + (n - miniIndex - 1);

    if(maxiIndex > miniIndex) ans -= 1;

    cout << ans << endl;

    return 0;
}