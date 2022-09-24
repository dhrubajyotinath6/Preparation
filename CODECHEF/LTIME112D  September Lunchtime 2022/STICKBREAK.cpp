//https://www.codechef.com/submit/STICKBREAK?tab=statement

#include <bits/stdc++.h>
using namespace std;


void solve(){
    int L, K;
    cin >> L >> K;
    
    if(L % K == 0){
        cout << 0 << endl;
        return;
    }
    
    cout << 1 << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
	    solve();
	}
	return 0;
}
