#include <iostream>
#include <cmath>

using namespace std;

class S;

class C
{
private: 
    int oradius, iradius, diff;
    double pie;
    
public:
    C(int a, int b)
    {
        oradius = a;
        iradius = b;
        pie = 3.14;
    }
    void set()
    {
        diff = trunc(pie*(oradius*oradius - iradius*iradius));
    }
    int get()const
    {
        return diff;
    }
    bool operator <= (const S &s1);
};

class S
{
private:
    int olength, ilength, diff;
    
public:
    S(int a, int b)
    {
        olength = a;
        ilength = b;
    }
    void set()
    {
        diff = olength*olength - ilength*ilength;
    }
    int get()const
    {
        return diff;
    }
    bool operator <= (const C &c1);
};

bool C::operator <= (const S &s1)
{
    return this->diff <= s1.get();
}

bool S::operator <= (const C &c1)
{
    return this->diff <= c1.get();
}

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    C c1(a, b);
    c1.set();
    S s1(c, d);
    s1.set();
    switch(e)
    {
        case 1:
        cout << c1.get() << '\n' << s1.get() << '\n';
        cout << (s1 <= c1 ? "Yes" : "No");
        break;
        case 2:
        cout << c1.get() << '\n' << s1.get() << '\n';
        cout << (c1 <= s1 ? "Yes" : "No");
        break;
    }
    
    return 0;
}