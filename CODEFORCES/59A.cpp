#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int upper = 0, lower = 0;

    for(auto &ch : s){
        if(isupper(ch)) upper++;
        else lower++;
    }

    if(upper > lower){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << endl;
    }else{
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    }

    return 0;
}