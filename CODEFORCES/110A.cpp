#include <bits/stdc++.h>
using namespace std;


bool isLucky(int num){

    bool flag = true;

    while(num > 0){
        int last = num % 10;
 
        if(last == 4 || last == 7){
            num = num/10;
        }else{
            flag = false;
            break;
        }
    }

    return flag;
}

int main(){

    int num;
    cin >> num;

    int count = 0;

    while(num > 0){
        int last = num % 10;
        num = num/10;    

        if(last == 4 || last == 7){
            count++;
        }
    }


   if(isLucky(count)){
    cout << "YES" << endl;
   }else{
    cout << "NO" << endl;
   }
   

return 0;
}