#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    string str;
    cin >> str;

    int i = 0, j = 0, ans = 0;

    // int n = str.length();

    while(i < n-1 ){

        if(str[i] != str[i+1]){
            i++;
        }else{
            j = i;
            char color = str[i];
            int count = 0;

            while(j < n && str[j] == color){
                j++;
                count++;
            }

            ans += (count - 1);
            i = j;
        }
    }

    cout <<  ans << endl;

    return 0;
}