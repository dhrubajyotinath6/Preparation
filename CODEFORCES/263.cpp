#include <bits/stdc++.h>
using namespace std;

int main(){

    int x = 2, y = 2;
    int x2 = 0, y2 = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int val;
            cin >> val;

            if(val == 1){
                x2 = i;
                y2 = j;
            }
        }
    }

    // cout << "x2 : " << x2 << endl;
    // cout << "y2: " << y2  << endl;

    int ans = abs(x-x2) + abs(y-y2);

    cout << ans << endl;


    return 0;
}