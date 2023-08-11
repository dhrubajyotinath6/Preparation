#include <bits/stdc++.h>
using namespace std;


bool isUnique(int num){
    string str = to_string(num);

    int n = str.length();
    set<char> s;

    for(int i = 0; i < n; i++){
        s.insert(str[i]);
    }

    return s.size() == n;
    
}


int main(){

    int n;
    cin >> n;
    
    int ans = n+1;
    bool flag = true;

    while(flag){
        
        if(isUnique(ans)) flag = false;
        else ans += 1;
    }

    cout << ans << endl;
    return 0;
}