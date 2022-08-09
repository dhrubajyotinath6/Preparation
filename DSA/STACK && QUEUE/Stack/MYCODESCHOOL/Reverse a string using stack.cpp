/*
THIS IS NOT THE MOST EFFICIENT METHOD TO REVERSE A STRING AS IT USE A STACK
THERE IS AN ANOTHER APPROACH WHICH USES 2 POINTERS AND THE SC IS O(1)
*/
#include<bits/stdc++.h>                TC -> O(N)
                                       SC -> O(N)
using namespace std;

string Reverse(string C, int n){

    stack<char> S;

    for(int i = 0; i < n; i++){
        S.push(C[i]);
    }

    for(int i = 0; i < n; i++){
        C[i] = S.top();
        S.pop();
    }

    return C;
}

int main(){

    string S;
    cout << "Enter the string: " << endl;
    cin >> S;
    cout << "Output : " << Reverse(S, S.size()) << endl;
    return 0;
}