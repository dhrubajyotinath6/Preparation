#include <iostream>
#include <vector>

using namespace std;

class dept1
{
    string customer_name;

public:
    string ph_no;

    void setname(string y)
    {
        customer_name = y;
    }

    void setph_no(int x)
    {
        ph_no = x;

        int flag2 = 0;

        // Checking if number is correct
        for (int i = 0; i < ph_no.length(); i++)
        {
            if (ph_no[i] - 48 >= 0 && ph_no[i] - 48 <= 9)
            {
                flag2 = 1;
                continue;
            }
            else
            {
                flag2 = 0;
                break;
            }
        }
    }
};

class dept2
{
    vector<string> i2;
    vector<int> p2;

    void get_item()
    {
        int n2;
        cout << "No of items in dept2:" << endl;
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            string item2;
            int price2;
            cout << "Item: " << endl;
            cin >> item2;
            i2.push_back(item2);
            cout << "Price: " << endl;
            cin >> price2;
            p2.push_back(price2);
        }
    }
};
class dept3
{
    vector<string> i3;
    vector<int> p3;

    void get_item()
    {
        int n3;
        cout << "No of items in dept3:" << endl;
        cin >> n3;
        for (int i = 0; i < n3; i++)
        {
            string item3;
            int price3;
            cout << "Item: " << endl;
            cin >> item3;
            i3.push_back(item3);
            cout << "Price: " << endl;
            cin >> price3;
            p3.push_back(price3);
        }
    }
};
class dept4
{
    vector<string> i4;
    vector<int> p4;

    void get_item()
    {
        int n4;
        cout << "No of items in dept4:" << endl;
        cin >> n4;
        for (int i = 0; i < n4; i++)
        {
            string item4;
            int price4;
            cout << "Item: " << endl;
            cin >> item4;
            i4.push_back(item4);
            cout << "Price: " << endl;
            cin >> price4;
            p4.push_back(price4);
        }
    } 
    
};
class dept5
{
    vector<string> i5;
    vector<int> p5;

     void get_item()
    {
        int n5;
        cout << "No of items in dept5:" << endl;
        cin >> n5;
        for (int i = 0; i < n5; i++)
        {
            string item5;
            int price5;
            cout << "Item: " << endl;
            cin >> item5;
            i5.push_back(item5);
            cout << "Price: " << endl;
            cin >> price5;
            p5.push_back(price5);
        }
    }
};

int main()
{
   dept1 customer;
   customer.setname("ram");
    return 0;
}