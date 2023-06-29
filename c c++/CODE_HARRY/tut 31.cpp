/*
Constructor Overloading in C++
Constructor overloading is a concept in which one class can have multiple constructors with
different parameters.
The main thing to note here is that the constructors will run according to the arguments
for example if a program consists of 3 constructors with 0, 1, and 2 arguments,
so if we pass 1 argument to the constructor the compiler will automatically run the constructor
which is taking 1 argument.


*/

#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex()
    {
        a = 0;
        b = 0;
    }

    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    Complex(int x)
    {
        a = x;
        b = 0;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    Complex c1(4, 6);
    c1.printNumber();

    Complex c2(5);
    c2.printNumber();

    Complex c3;
    c3.printNumber();
    return 0;
}
