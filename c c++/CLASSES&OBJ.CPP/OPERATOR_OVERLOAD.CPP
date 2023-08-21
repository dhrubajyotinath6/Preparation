 // OPERATOR  OVERLOADING

#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;
public:

    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(int r, int i){
        real = r;
        imag = i;
    }

    void print(){
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator +(Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }
};

int main(){
    Complex c1(5,4);
    Complex c2(4,2);

    Complex c3;

    c3 = c1 + c2;       // c3 = c1.add(c2)
    c3.print();

    return 0;
}

/////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Weight{
    private:
        int kg;

    public:
        Weight(){
            kg = 0;
        }

        void printWeight(){
            cout << "Weight in kg: " << kg << endl;
        }

        void operator ++(){
            ++kg;
        }

        void operator ++(int){
            kg++;
        }

};

int main(){
    
    Weight obj1;
    obj1.printWeight();

    ++obj1;
    obj1.printWeight();

    return 0;
}

