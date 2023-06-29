//Revisiting Pointers: new and delete Keywords in CPP
/*

#include<iostream>
using namespace std;

int main(){
    // Basic Example
    int a = 4;
    int* ptr = &a;
    *ptr = 999;
    cout<<"The value of a is "<<*(ptr)<<endl;

    // new operator
    // int *p = new int(40);
    float *p = new float(40.78);
    cout << "The value at address p is " << *(p) << endl;

    int *arr = new int[3];
    arr[0] = 10;
    *(arr+1) = 20;
    arr[2] = 30;
    // delete[] arr;
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;

    // delete operator
    
    return 0;
}
*/

#include<iostream>
using namespace std;

class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b){
            real = a;
            imaginary = b;
        }

};
int main(){
    // Complex c1;
    // Complex *ptr = &c1;
    Complex *ptr = new Complex;
    // (*ptr).setData(1, 54); is exactly same as
    ptr->setData(1, 54);

    // (*ptr).getData(); is as good as 
    ptr->getData(); 

    
    // Array of Objects
    Complex *ptr1 = new Complex[4]; 
    for(int i = 0; i < 4; i++){
        ptr1->setData(1, 4); 
        ptr1->getData();
        ptr++;
    }
    
    return 0;
}

