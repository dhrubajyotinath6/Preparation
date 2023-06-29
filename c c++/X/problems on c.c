//TO FIND THE AREA AND CIRCUMFERENCE OF THE CIRCLE
/*
#include<stdio.h>
int main()
{
float rad,area,circum;
printf("\nEnter the radius of the circle: ");
scanf("%f",&rad);
area=3.14*rad*rad;
circum=2*3.14*rad;
printf("\nArea=%f",area);
printf("\nCircumference=%f",circum);
} */

//INSERTING AN ELEMENTS INTO THE VECTOR
/*
#include<stdio.h>
#include<stdio.h>
int main()
{
int a[100],no,i,pos,item;
printf("\nEnter the size of the matrix : ");
scanf("%d",&no);
printf("\nEnter the elements of the matrix:\n");
for(i=0;i<no;i++)
scanf("%d",&a[i]);
printf("\nEntered elements of the matrix is: \n");
for(i=0;i<no;i++)
printf("\n%d",a[i]);
printf("\nEnter the element and its position in the array: \n");
scanf("%d\n%d",&item,&pos);
no++;
for(i=no;i>=pos;i--)
a[i]=a[i-1];
a[-pos]=item;
printf("\n");
printf("\nArray after the insertion:\n");
for(i=0;i<no;i++)
printf("\n%d",a[i]);
} */
