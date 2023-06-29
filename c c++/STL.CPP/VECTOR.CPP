#include <iostream>
#include <vector>

using namespace std;
 
template <class T>
void display(vector<T> &v)
{

    cout << "Displaying : \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " at ";
        cout << v.at(i) << " \n";
    }
}

int main()
{
    //Ways to create a vector
    vector<int> vec1;        // zero length integer vector
    vector<char> vec2(4);    // 4-element character vector
    vector<char> vec3(vec2); //  4-element character vector from vec2
    vector<int> vec(6, 3);   // 6-element vector of 3s
    int element, size = 5;

    // display(vec1);

    // vec2.push_back('5');
    // display(vec2);

    // cout << "SIZE:  \n";
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter an element to add to this vector";
    //     cin >> element;
    //     vec1.push_back(element);
    // }

    //vec1.pop_back();
    // display(vec1);
    // vector <int> :: iterator iter = vec1.begin();
    // // vec1.insert(iter+1, 3, 566);
    // display(vec1);
    // return 0;
}