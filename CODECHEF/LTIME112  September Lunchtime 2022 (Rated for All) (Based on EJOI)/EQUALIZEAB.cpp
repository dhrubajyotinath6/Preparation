//https://www.codechef.com/submit/EQUALIZEAB?tab=statement

INPUT:
4
5 7 1
3 4 2
4 4 6
2 5 3

output:
YES
NO
YES
NO


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int A, B,X;
    cin >> A >> B >> X;
    
    // 4 4 6 
    if(A == B){
        cout << "Yes" << endl;
        return;
    }
    
    int x = abs(A-B);
    
    /*
    A = 24, B = 12 , X = 12
    it will give yes but actually no
    */
    // if(x%2 == 0 && x%X==0){  ->why this not works??
    //     cout << "Yes" << endl;
    //     return;
    // }
    X = 2*X;
    
    if(x % X == 0){
        cout << "Yes" << endl;
        return;
    }
    
    cout << "No" << endl;
    
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

