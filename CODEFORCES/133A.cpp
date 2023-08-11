#include <bits/stdc++.h>
using namespace std;

int main(){

    //HQ9+
    string str = "HQ9+";
    set<char> s(str.begin(), str.end());
    s.erase('+');

    string input;
    cin >> input;

    bool flag = false;

    for(auto& it : input){
        if(s.find(it) != s.end()){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl;
        return 0;
    }else{
        cout << "NO" << endl;
        return 0;
    }

    return 0;
}