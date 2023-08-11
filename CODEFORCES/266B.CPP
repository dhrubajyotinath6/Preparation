#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int t;
    cin >> t;

    string s;
    cin >> s;


    for(int time = 0; time < t; time++){

        int i = 1;

         while(i < n){
            if(s[i-1] == 'B' && s[i] == 'G'){
                s[i-1] = 'G';
                s[i] = 'B';
                i += 2;
            }else{
                i += 1;
            }
         }

    }

    cout << s << endl;

   

    return 0;
}