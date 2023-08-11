#include <bits/stdc++.h>
using namespace std;


int main(){

    // vector<int> prime {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

    unordered_map<int,int> mpp{
              {2,1},
              {3,2},
              {5,3},
              {7,4},
              {11,5},
              {13,6},
              {17,7},
              {19,8},
              {23,9},
              {29,10},
              {31,11},
              {37,12},
              {41,13},
              {43,14},
              {47,15}
          };

    int n, m;
    cin >> n;
    cin >> m;

    if(mpp[n] + 1 == mpp[m]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}