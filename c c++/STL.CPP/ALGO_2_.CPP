#include <bits/stdc++.h>

using namespace std;

int main(){
    // cout << [](int x){return x+2;}(4) << endl;  // 6

    // cout << [](int x, int y){return x+y;}(4, 8) << endl;  // 12

    auto sum = [](int x, int y){return x+y;};
    cout << sum(2,5) << endl;  //7

    vector<int> v = {2,-5,-4};
    cout << all_of(v.begin(), v.end(), [](int x){return x > 0;}) << endl;  // 0
    cout << any_of(v.begin(), v.end(), [](int x){return x > 0;}) << endl;  // 1
    cout << none_of(v.begin(), v.end(), [](int x){return x > 0;}) << endl; // 0

    return 0;
}