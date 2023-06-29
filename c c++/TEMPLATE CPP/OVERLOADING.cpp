#include <iostream>
using namespace std;

template <class T>
class Harry
{
public:
    T data;
    Harry(T a)
    {
        data = a;
    }
    void display();
};

template <class T>
void Harry<T>::display(){
    cout << data;
}

void func(int a){
    cout << "I m a First Func() " << a << endl;
}

template <class T>
void func(T a){
    cout << "I m a First Func() " << a << endl;
}

int main()
{
    // Harry<int> h(5);
    // cout << h.data;

    // cout << endl;

    // h.display();

    func(4);
    return 0;
}