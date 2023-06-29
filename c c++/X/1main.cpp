//  3.2  SWITCH CASE STATEMENTS

//Ques1. Write a program to write a simple calculator.

#include <iostream>
using namespace std;

int main() {

 int n1,n2;
 char op;

 cout<<"Enter 2 numbers: ";
 cin>>n1>>n2;

 cout<<"Enter operand: ";
 cin>>op;

 switch (op)
 {
 case '+':
 cout<<n1+n2<<endl;
 break;

 case '-':
 cout<<n1-n2<<endl;
 break;

 case '*':
 cout<<n1*n2<<endl;
 break;

 case '/':
 cout<<n1/n2<<endl;
 break;

 case '%':
 cout<<n1%n2<<endl;
 break;

 default:
 cout<<"Operator not found!"<<endl;
 break;
 }

 return 0;
} 

/*
// Ques2. Write a program to find whether an alphabet is a vowel or a consonant.
#include <iostream>
using namespace std;

int main() {

 char c;

 cout<<"Enter an alphabet: ";
 cin>>c;


 //if(isupper(c)){
 //     c= c+32;  // +32 converts capital letter to lower letter A/Q to ASCII
 //}
 
 c=tolower(c);  // for 'A' ie for capital letter we have to check

 switch (c)
 {
 case 'a':
 cout<<"It is a vowel"<<endl;
 break;

 case 'e':
 cout<<"It is a vowel"<<endl;
 break;

 case 'i':
 cout<<"It is a vowel"<<endl;
 break;

 case 'o':
 cout<<"It is a vowel"<<endl;
 break;

 case 'u':
 cout<<"It is a vowel"<<endl;
 break;

 default:
 cout<<"It is a consonant"<<endl;
 break;
 }

 return 0;
}
*/

//~~~~~~~~~~4 PATTERN QUESTIONS~~~~~~~~~~~


#include <iostream>
using namespace std;
int& chk()
{
    int i = 5;
    return i;
}

int main()
{
    int a;
    a=chk();
    cout << endl << a;
    return 0;
}