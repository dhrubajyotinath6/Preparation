#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(3,0);

    for(int i = 0; i < n; i++){

        for(int j = 0; j < 3; j++){
            int x;
            cin >> x;
            arr[j] += x;
        }
    }


    for(int i = 0; i < 3; i++){
        if(arr[i] != 0){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}

/*
3
4 1 7
-2 4 -1
1 -5 -3
 
*/

/*
3
3 -1 7
-5 2 -4
2 -1 -3

*/