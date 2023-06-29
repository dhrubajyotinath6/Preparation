#include <iostream>
#include <list>

// /*/*-----VISIT CPLUSPLUS-----*/*/
using namespace std;

void display(list<int> &lst){
    list<int> :: iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
} 

int main(){

    list<int>list1; // List of 0 Length
    

    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);

    // list<int> :: iterator iter;
    // iter = list1.begin();

    // cout << *iter << " ";
    // iter++;
    // cout << *iter << " ";
    // iter++;
    // cout << *iter << " ";
    // iter++;
    // cout << *iter << " ";
    // iter++;

    display(list1);
    list1.pop_back();
    display(list1);


    list<int> list2(3); // Empty list of size 3
    list<int> :: iterator iter;
    iter = list2.begin();

    *iter = 45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;

    display(list2);



    return 0;
}