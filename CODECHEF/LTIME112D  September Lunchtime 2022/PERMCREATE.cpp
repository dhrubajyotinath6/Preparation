//https://www.codechef.com/submit/PERMCREATE?tab=statement

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    
    if(N == 2 || N == 3){
        cout << -1 << endl;
        return;
    }
    
    // if(N == 1){
    //     cout << 1 << endl;
    //     return;
    // }
    /*
    1 2 3 4 5 6 7
    1 3 5 7 2 4 6
    
    1 2 3 4 
    4 2 1 3
    */
    
    for(int i = 2; i <= N; i++){
        if(i % 2 == 0) cout << i << " ";
    }
    
    for(int i = 1; i <= N; i++){
        if(i % 2 == 1) cout << i << " ";
    }
    
    
    
    cout << endl;
}

int main() {
    
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        solve();
    }
	// your code goes here
	return 0;
}
