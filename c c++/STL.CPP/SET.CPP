#include <iostream>
#include <set>

using namespace std;

void print(set<string> &s){
    for(string value : s){
        cout << value << endl;
    }
    cout << endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << (*it) << endl;
    }
}
int main(){
    set<string> s;
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");

    // auto it = s.find("abc");
    // if(it != s.end()){
    //     cout << (*it) << endl;
    // }

    auto it = s.find("abc");
    if(it != s.end()){
       s.erase(it);
    }
    // s.erase("abc");

    print(s);
    return 0;
}