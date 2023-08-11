#include <bits/stdc++.h>
using namespace std;


int main(){

    string s;
    cin >> s;

    int n = s.length();


    int i = 0;

    string ans = "";

    while(i < n){
        
        if(s[i] == '.'){
            ans += '0';
            i++;
        }else if(s[i] == '-'){

            if(s[i+1] == '.') ans += '1';
            else if(s[i+1] == '-') ans += '2';

            i += 2;
        }
    }

    cout << ans << endl;

    return 0;
}