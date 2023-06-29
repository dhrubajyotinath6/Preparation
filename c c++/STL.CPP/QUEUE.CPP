#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<string> q;
    q.push("abc");
    q.push("cde");
    q.push("erw");
    q.push("asd");
    while (!q.empty())
    {
       cout << q.front() << endl;
       q.pop();
    }
    
    return 0;
}