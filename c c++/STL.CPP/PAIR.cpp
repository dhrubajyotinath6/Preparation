#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printVec(vector<pair<int,int> > &v){
       cout << "size: " << v.size() << endl;
       for(int i = 0; i < v.size(); i++){
           cout << v[i].first << "  " << v[i].second << endl;
       }
       cout << endl;
   }
   
int main(){
    /*
    pair<int,string> p;
   // p = make_pair(2, "abc");
    p = {2, "abc"};

    // pair<int, string> p1 = p;
    // p1.first = 3;   // 2 abc

    pair<int, string> &p1 = p;
    p1.first = 3;      // 3 abc

    cout << p.first << " " << p.second << endl;
    */
   

   vector<pair<int, int>> v;
   printVec(v);
   int n;
   cin >> n;
   for(int i = 0; i < n; i++){
       int x, y;
       cin >> x >> y;
       v.push_back(make_pair(x,y)); // v.push_back{x,y});
   }
   printVec(v);
    return 0;
}