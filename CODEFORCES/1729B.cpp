#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n;
    cin >> n;

    int arr[n];
    string ans;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int i = n-1;

    while(i >= 0){

        if(arr[i] != 0){
            
            int currNo = arr[i];
            char ch = 'a' + currNo - 1;
            ans += ch;
            i--;
            if(i < 0) break;
        }

        if(arr[i] == 0){
            long currNo = arr[i-2]*10 + arr[i-1];
            char ch = 'a' + currNo - 1;
            ans += ch;
            i -= 3;
            if(i < 0) break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

}

int main(){

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        solve();
    }
}

