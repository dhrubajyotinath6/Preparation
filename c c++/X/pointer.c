/*
#include <stdio.h>
int main()
{                                   
 // Pointer of integer type, this can hold the address of a integer type variable. 
 int *p;
 int var = 10;
 // Assigning the address of variable var to the pointer p. The p can hold the address of var
 //because var is an integer type variable. 
 p= &var;
 printf("Value of variable var is: %d", var);
 printf("\nValue of variable var is: %d", *p);      // p= &var; *P= *(&var)
 printf("\nAddress of variable var is: %p", &var);
 printf("\nAddress of variable var is: %p", p);
 printf("\nAddress of pointer p is: %p", &p);
 return 0;
} 
*/
/*
// Pointers and Strings with Examples
#include <stdio.h>
#include <string.h>
int main()
{
char str[]="Hello Guru99!";        // variable_name[size]
char *p;
p=str;                             //We can also type simply p=&str[0] 
printf("First character is:%c\n",*p);
p =p+1;
printf("Next character is:%c\n",*p);
printf("Printing all the characters in a string\n");
p=str; //reset the pointer
for(int i=0;i<strlen(str);i++)
{
printf("%c   ",*p);
printf("%p   \n",p);
p++;
}
return 0;
}   
*/
//C program to print a string using pointer.
/*#include <stdio.h>
int main()
{
 char str[100];
 char *ptr;

 printf("Enter a string: ");
 gets(str);
 
 //assign address of str to ptr
 ptr=str;

 printf("Entered string is: ");
 while(*ptr!='\0')
 printf("%c",*ptr++);

 return 0;
}  */
/*
#include <stdio.h>
int main()
{
 int num=123;
 int *pr2; //A normal pointer pr2
 int **pr1; //This pointer pr2 is a double pointer
 pr2 = &num;
 pr1 = &pr2;
// num, &num, pr2, *pr2,pr1, *pr1=*(66X123X1), **pr1
 // Possible ways to find value of variable num
 printf("\n Value of num is: %d", num);
 printf("\n Value of num using pr2 is: %d", *pr2);// (*(&num))
 printf("\n Value of num using pr1 is: %d", **pr1); // *(*(&pr2)) // 123
 //Possible ways to find address of num
 printf("\n\n\n Address of num is: %p", &num);
 printf("\n Address of num using pr2 is: %p", pr2);
 printf("\n Address of num using pr1 is: %p", *pr1);
 //Find value of pointer
 printf("\n\n\n Value of Pointer pr2 is: %p", pr2);
 printf("\n Value of Pointer pr2 using pr1 is: %p", *pr1);
 //Ways to find address of pointer
 printf("\n\n\n Address of Pointer pr2 is:%p",&pr2);
 printf("\n Address of Pointer pr2 using pr1 is:%p",pr1);
 //Double pointer value and address
 printf("\n\n\n Value of Pointer pr1 is:%p",pr1);
 printf("\n Address of Pointer pr1 is:%p",&pr1);
 return 0;
} */

/*   num == *pr2 == **pr1
     &num == pr2 == *pr1
     &pr2 == pr1  */

//NULL POINTER
/*
#include <stdio.h>
int main()
{
int *p = NULL; //null pointer
printf("The value inside variable p is:\n%x",p);
return 0;
} */
// VOID POINTER
/*
#include <stdio.h>
int main()
{
void *p = NULL; //void pointer
printf("The size of pointer is:%d\n",sizeof(p));
return 0;
} */

//Passing pointer to a function in C with example
/*
#include <stdio.h>
void salaryhike(int *var, int b)
{
 *var = *var+b;
}
int main()
{
 int salary=0, bonus=0;
 printf("Enter the employee current salary:");
 scanf("%d", &salary); //50000
 printf("Enter bonus:"); //2000
 scanf("%d", &bonus);
 salaryhike(&salary, bonus);
 printf("Final salary: %d", salary);
 return 0;
}
*/

// Swapping two numbers using Pointers
/*
#include <stdio.h>
void swapnum(int *num1, int *num2)
{
 int tempnum;
 tempnum = *num1;
 *num1 = *num2;
 *num2 = tempnum;
}
int main( )
{
 int v1 = 11, v2 = 77 ;
 printf("Before swapping:");
 printf("\nValue of v1 is: %d", v1);
 printf("\nValue of v2 is: %d", v2);
 //calling swap function
 swapnum( &v1, &v2 );
 printf("\nAfter swapping:");
 printf("\nValue of v1 is: %d", v1);
 printf("\nValue of v2 is: %d", v2);
} */

/*
function_return_type(*Pointer_name)(function argument list)
double (*p2f)(double, char)*/
// Function Pointer with examples
/*
#include <stdio.h>
int sum (int num1, int num2)
{
 return num1+num2;
}
int main()
{
 int (*f2p) (int, int);
 f2p = sum;
 //Calling function using function pointer
 int op1 = f2p(10, 13);
 //Calling function in normal way using function name
 int op2 = sum(10, 13);
 printf("Output1: Call using function pointer: %d",op1);
 printf("\nOutput2: Call using function name: %d", op2);
 return 0;
} */

//Pointer and Array in C programming with example
/*
#include <stdio.h>
int main( )
{
 //Pointer variable
 int *p;
 //Array declaration
 int val[7] = { 11, 22, 33, 44, 55, 66, 77 } ;
 // Assigning the address of val[0] the pointer
 // You can also write like this:
 // p = var;
 // because array name represents the address of the first element
 
 p = &val[0];
 for ( int i = 0 ; i<7 ; i++ )
 {
 printf("val[%d]: value is %d and address is %p\n", i, *p, p);
 // Incrementing the pointer so that it points to next element
 // on every increment.
 
 p++;
 }
 return 0;
} */
/*
#include <stdio.h>
int main( )
{
 int *p;
 int val[7] = { 11, 22, 33, 44, 55, 66, 77 } ;
 p = val;
 for ( int i = 0 ; i<7 ; i++ )
 {
 printf("val[%d]: value is %d and address is %p\n", i, *(p+i), (p+i));
 }
 return 0;
}
//   *(a+i) a[i], i[a], *(i+a)
*/
/*
#include <stdio.h>
int main() {
 int x[5] = {1, 2, 3, 4, 5};
 int* ptr;
 // ptr is assigned the address of the third element
 ptr = &x[2];
 printf("*ptr = %d \n", *ptr); // 3
 printf("*(ptr+1) = %d \n", *(ptr+1)); // 4
 printf("*(ptr-1) = %d", *(ptr-1)); // 2
 return 0;
}   */

//Array of pointers
/*
#include <stdio.h>
const int MAX = 3;
int main () {
 int var[] = {10, 100, 200};
 int i, *ptr[MAX];
 for ( i = 0; i < MAX; i++) {
 ptr[i] = &var[i]; //  assign the address of integer. 
 }

 for ( i = 0; i < MAX; i++) {
 printf("Value of var[%d] = %d\n", i, *ptr[i] );
 }

 return 0;
} */

//  Pointers and two dimensional arrays
/*
#include <stdio.h>
int main()
{
 int arr[3][4] = {
 {11,22,33,44},
 {55,66,77,88},
 {11,66,77,44}
 };
 int i, j;
 for(i = 0; i < 3; i++)
 {
 printf("Address of %d th array %u \n",i , *(arr + i));
 for(j = 0; j < 4; j++)
 {
 printf("arr[%d][%d]=%d\n", i, j, *( *(arr + i) + j) );
 }
 printf("\n\n");
 }
 // signal to operating system program ran fine
 return 0;
} */

//Print student details using structure pointer, demonstrate example of structure with
//pointer.
//C program to read and print student details using structure pointer,
//demonstrate example of structure with pointer.
/*
#include <stdio.h>
struct student{
 char name[30];
 int roll;
 float perc;
};
int main()
{
 struct student std; //structure variable
 struct student *ptr; //pointer to student structure

 ptr= &std; //assigning value of structure variable
 std.name="anu"; std.roll =10; std.perc=8.0;
ptr->name="priya";ptr->roll=20;ptr->perc=9.0;
 printf("Enter details of student: ");
 printf("\nName ?:"); gets(ptr->name);
 printf("Roll No ?:"); scanf("%d",&ptr->roll);
 printf("Percentage ?:"); scanf("%f",&ptr->perc);

 printf("\nEntered details: ");
 printf("\nName:%s \nRollNo: %d \nPercentage: %.02f\n",ptr->name,ptr->roll,ptr->perc);
 return 0;
} */
/*
#include <stdio.h>
struct student { // student structure
 char id[15];
 char firstname[64];
 char lastname[64];
 float points;
};
// function declaration
void getDetail(struct student *);
void displayDetail(struct student *);
int main(void) {
 // student structure variable
 struct student std[3];
 getDetail(std); // get student detail
 displayDetail(std); // display student detail
 return 0;
}
// function definition
void getDetail(struct student *ptr) {
 int i;
 for (i = 0; i < 3; i++) {
 printf("Enter detail of student #%d\n", (i + 1));
 printf("Enter ID: ");
 scanf("%s", ptr->id);
 printf("Enter first name: ");
 scanf("%s", ptr->firstname);
 printf("Enter last name: ");
 scanf("%s", ptr->lastname);
 printf("Enter Points: ");
 scanf("%f", &ptr->points);
 // update pointer to point at next element of the array std
 ptr++;
 }
}
void displayDetail(struct student *ptr) {
 int i;
 for (i = 0; i < 3; i++) {
 printf("\nDetail of student #%d\n", (i + 1));
 // display result via ptr variable
 printf("\nResult via ptr\n");
 printf("ID: %s\n", ptr->id);
 printf("First Name: %s\n", ptr->firstname);
 printf("Last Name: %s\n", ptr->lastname);
 printf("Points: %f\n", ptr->points);
 // update pointer to point at next element of the array std
 ptr++;
 }
} */






   




