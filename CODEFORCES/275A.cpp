#include <bits/stdc++.h>
using namespace std;


int neigh(vector<vector<int>> &mat, int i, int j){

    int count = mat[i][j];

    if(i - 1 >= 0)
        count += mat[i-1][j];
    if(i + 1 < 3)
        count += mat[i+1][j];
    if(j - 1 >= 0)
        count += mat[i][j-1];
    if(j + 1 < 3)
        count += mat[i][j+1];

    if(i - 1 >= 0 && j - 1 >= 0)
        count += mat[i-1][j-1];
    if(i - 1 >= 0 && j + 1 < 3)
        count += mat[i-1][j+1];
    if(i + 1 < 3 && j - 1 >= 0)
        count += mat[i+1][j-1];
    if(i + 1 < 3 && j + 1 < 3)
        count += mat[i+1][j+1];

    return count;

    
}



int main(){

    vector<vector<int>> mat(3, vector<int>(3));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
        }
    }

    // vector<vector<int>> ans(3,vector<int>(3,1));

    int ans = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            int count = neigh(mat, i,j);

            if(i == 1 && j == 1) ans = count;

            if(count % 2 == 0){
                cout << 1;
            } 
            else {
                cout << 0;
            }
        }

        cout << endl;
    }

    cout << ans << endl;



    return 0;
}