/*
Virtual Base Class in C++

https://www.codewithharry.com/videos/cpp-tutorials-in-hindi-44/   --VERY VERY IMP


*/

#include <iostream>
using namespace std;
class A
{
public:
    void say()
    {
        cout << "Hello world" << endl;
    }
};
class B : public virtual A
{
};
class C : public virtual A
{
};
class D : public B, public C
{
};
