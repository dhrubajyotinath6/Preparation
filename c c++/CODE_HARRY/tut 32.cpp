/*
Constructors with Default Arguments in C++
Default arguments of the constructor are those which are provided in the constructor declaration.

If the values are not provided when calling the constructor the constructor uses the default arguments
automatically

*/

#include <iostream>
using namespace std;

class Simple
{
    int data1;
    int data2;
    int data3;

public:
    Simple(int a, int b = 9, int c = 8)
    {
        data1 = a;
        data2 = b;
        data3 = c;
    }

    void printData();
};

void Simple ::printData()
{
    cout << "The value of data1, data2 and data3 is " << data1 << ", " << data2 << " and " << data3 << endl;
}

int main()
{
    Simple s(12, 13);
    s.printData();
    return 0;
}
