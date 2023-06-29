#include <iostream>
#include <stack>


using namespace std;

int main(){
    stack<int>s;
    s.push(2);
    s.push(9);
    s.push(1);
    s.push(-98);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    
    return 0;
}
