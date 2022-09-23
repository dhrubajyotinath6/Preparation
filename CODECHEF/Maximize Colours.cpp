//https://www.codechef.com/submit/COLOUR?tab=statement

#include <bits/stdc++.h>
using namespace std;


void solve(){
    
    vector<int> arr(3);
    
    for(int i = 0; i < 3; i++){
        int X;
        cin >> X;
        arr[i] = X;
    }
    
    sort(arr.begin(),arr.end());
    
    int ans = 0;
    
    for(int i = 0; i < 3; i++){
        if(arr[i]){
          ans++;
          arr[i]--;
        } 
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            
            if(arr[i] && arr[j]) {
                ans++;
                arr[i]--, arr[j]--;
            }
                
        }
    }
    
    cout << ans << endl;
    
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


/*
https://discuss.codechef.com/t/colour-editorial/103188/14

we need to sort it  -> code will get stuck in the test case 2 2 3 which should ideally give 5 
                        but code will give 4 as output. So sort it first.



*/