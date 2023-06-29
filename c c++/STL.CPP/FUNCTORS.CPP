#include <iostream>
#include <functional>
#include <algorithm>


using namespace std;

int main(){

    int arr[] = {78, 3, 12, 888, 12, 1};
    sort(arr, arr+5);
   // sort(arr, arr+5, greater<int>());
    

    for(int i = 0; i < 6; i++){
        cout << arr[i] << "  ";
    }
    return 0;
}