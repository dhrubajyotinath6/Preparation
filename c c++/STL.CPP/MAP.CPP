#include <iostream>
#include <map>
using namespace std;
// /*/*-----VISIT CPLUSPLUS-----*/*/
/*


int main(){

    map<string, int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 35;
    marksMap["Rohan"] = 8;

    marksMap.insert({{"yoo", 67}, {"qwerty", 789}});

    map<string, int> :: iterator iter;
    for(iter = marksMap.begin(); iter != marksMap.end(); iter++){
        cout << (*iter).first << " " << (*iter).second << "\n";
    }

    cout << "The size is: " << marksMap.size() << endl;

    return 0;
}
*/
void print(map<int,string> &m){
    cout << m.size() << endl;

    for(auto &pr : m){
        cout << pr.first << " " << pr.second << endl;
    }
}

int main(){

    map<int, string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";

    m.insert({4, "afg"});

    // map<int, string> :: iterator it;
    // for(it = m.begin(); it != m.end(); it++){
    //     cout << (*it).first << " " << (*it).second << endl;
    // }

    auto it = m.find(3);
    if(it == m.end()){
        cout << "No value";
    }
    else{
         cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}