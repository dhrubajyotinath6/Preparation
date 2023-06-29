/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

 class test
 {
   int len;
   char d[10];
   char *d2;

   public:
       test()  {len = 0;}
       
       test (int x, char *str){len = x;  strcpy(d, str);}

       
       test(char *str) { len = strlen(str); d2 = new char(len); strcpy(d2, str);}
       

       void update(char *str){strcpy(d, str); len = strlen(d);}

       void update(char *str) {strcpy(d2, str2); len = strlen(d2);}

       void op() const  { cout << endl << len << endl << d;}
      
       void op() const { cout << endl << len << endl << d2; }
       
 };

 int main()
 {
   test t1(5, "Hello");
   test t1("Hello");
   test t2;
   t2 = t1;
   t1.op();
   t2.op();
   t1.update("You");
   t1.op();
   t2.op();

   return 0;
 }

 */
/*
void ttst ( int t)
{
    try
    {
        if (t == 0) throw t;
        if (t == -1) throw 't';
        if (t == 1) throw 1.0;
        cout << "\nHello you have entered " << t;
    }
    catch(...)
    {
         cout << "\nInside the catch block";
    }
    
}

int main()
{
    cout << "\nIn main now ";
    ttst(0);
    ttst(1);
    ttst(-1);
}
*/

/*
int main()
{
    int x = 7;
    int &ref = x;
    ref = 8;
    cout << "\n x = " << x << "\n ref = " << ref;
    int y = 10;
    ref = y;
    cout << "\n x = " << x << "\n y = " << y << "\n ref = " << ref;

    return 0;
}
*/
/*
void swapp( int *i, int *j)
{
    int ttmp;
    ttmp = *i;   *i = *j;  *j = ttmp;
}

int main()
{
    int x = 5, y=3;
    int *a = &x, *b=&y;
    cout << endl << "Before :" << x << " and " << y;
    swapp(a,b);
    cout << endl << "After :" << x << " and " << y;
}
*/
/*
void swapp( int &i, int &j)
{
    int ttmp;
    ttmp = i;   i = j;  j = ttmp;
}

int main()
{
    int x = 5, y=3;
    int &a = x, &b=y;
    cout << endl << "Before :" << x << " and " << y;
    swapp(a,b);
    cout << endl << "After :" << x << " and " << y;
}
*/
/*
int x = 10;

int main()
{
    int x = 5;
    cout << x << endl << ::x;
}
*/
/*
class test
{
    int x;

    public:
        void readx(int x)
        { this->x = x; }
        void otpt()
        { cout << endl << " The value of the private data member is :" << x;}
};

int main()
{
    test t;
    t.readx(10);
    t.otpt();

    return 0;
}
*/
/*
int& chk()
{ int i = 5; return i; }

int main()
{
    int a;
    a = chk();
    cout << endl << a;

    return 0;
}
*/
/*
int& op( int a[], int i)
{
    a[i]++; return a[i];
}

int main()
{
    int b[5]; int a, i;
    for(i = 0; i < 5; i++)
    {
        b[i] = i;
    }

    a = op(b,3);
    cout << "After function call : ";

    for (i = 0; i < 5; i++)
    {
        cout << endl << b[i];
    }

    cout << endl << " Value after update :" << a;
}
*/
/*
class time
{
    int hour;
    public:
        time(int a)
        {
            hour = a;
        }

        void update()
        {
            hour++;
        }

        int value() const
        {
            return hour;
        }

        int update2() const
        {
            hour--;
        }

};

int main()
{
    time t(10);
    cout << "Hour :" << t.value();
}
*/

