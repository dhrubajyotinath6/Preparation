#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }

    int maxi = arr[0], mini = arr[0], ans = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] > maxi){
            ans++;
            maxi = arr[i];
        }

        if(arr[i] < mini){
            ans++;
            mini = arr[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}