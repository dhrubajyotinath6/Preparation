//https://www.codechef.com/submit/ARREQU?tab=statement

/*

*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int n;
    cin >> n;
    
    int limit = ceil((double)n/2);
    
    unordered_map<int,int> mpp;
    bool flag = true;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mpp[x]++;
        
        if(mpp[x] > limit ) {
            flag = false;
        }
    }
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	for(int i = 0; i < T;i++){
	    solve();
	}
	return 0;
}

/*
3 3 4 

3 -> 2 
4 -> 1 
*/
