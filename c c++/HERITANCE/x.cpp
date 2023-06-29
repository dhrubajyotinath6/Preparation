#include <iostream>
using namespace std;

class part_time
{
    int pdegreecredits;
    int pcreditcost;
    int pcredityear;

public:
    void get_data1(int a, int b, int c)
    {
        pdegreecredits = a;
        pcreditcost = b;
        pcredityear = c;
    }
};

class full_time
{
    int fdegreecredits;
    int fcreditcost;
    int fcredityear;

public:
    void get_data2(int d, int e, int f) 
    {
        fdegreecredits = d;
        fcreditcost = e;
        fcredityear = f;
    }
};


class Employee : public part_time, public full_time{

    int bankbalance;
    int yearlysal;
    int age;
    int manage;
    int choice;

    public:
    void get_data3(int a, int b, int c, int d, int e){
        bankbalance = a;
        yearlysal = b;
        age = c;
        manage = d;
        choice = e;
    }

};

int main()
{

    return 0;
}