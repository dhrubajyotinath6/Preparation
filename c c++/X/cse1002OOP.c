#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
struct Student{
  char name[20];
  char major[20];
  int age;
  double gpa;
};
int main(){

  struct Student s1;
  s1.age = 20;
  s1.gpa = 3.9;
  strcpy(s1.name , "Dhruba");
  strcpy(s1.major , "Engineering");
  
  struct Student s2;
  s2.age = 22;
  s2.gpa = 3.56;
  strcpy(s2.name , "Mike");
  strcpy(s2.major , "Computer");

  printf("%s", s2.name);
  
  return 0;
} 
*/
/*

int main(){
  int i = 2;
    double A[] = {23.67, 56.2, 2.4, 6.7, 8.9, 5.6, 6.7};
    printf("%f \n",A[i++]);  // 2.4
    printf("%d \n",i);        // 3

    printf("%f",A[i--]);     // 2.4
    printf("%d \n",i);       // 1

    printf("%f",A[++i]);      // 6.7
    printf("%d \n",i);

    printf("%f",A[--i]);        // 56.2
    printf("%d \n",i);
} */
/*
int main(){
     int days, i, acc[20], total=0;
     float mean;

     printf("Enter no of days :\n");
     scanf("%d", &days);
     
     for (i = 0 ; i < days; i++){
          printf("Enter no of accidents happen in %d day :\n", i+1);
          scanf("%d", &acc[i]);
          total += acc[i];
     }
      mean = (float)total/(float)days;
      printf("Average is :%.2f\n" , mean);
 
    for (i = 0; i < days; i++){
      printf("%.2f ", mean-acc[i]);
    }  
} */
/*
int main(){
  char s1[5] = "abc";
  char s2[5] ="def";
  strcpy(s1, s2);
  printf("%s\n", s1);
  printf("%s\n", s2);
} */
/*
int fact(int n){
     if (n == 1){
        return 1;
     }
     else {
       return n*fact(n-1);
     }
}

int main(){
  int n, ans;
  printf("The no is :");
  scanf("%d",&n);
  ans = fact (n);
  printf("Answer is :%d", ans);
} */
/*
int main(){

  int n = 10 , m = 5;
  float f = 23;
  int *p;
   //p = &n;
  //*p= 12;
  p= &f;
  printf("f = %f through pointer = %d %d \n", f , *p, p);
 // printf("n = %d through pointer = %d %d \n", n , *p, p);
 // p = &m;
 // *p = 6;
  //printf("m = %d through pointer = %d   %d",m, *p, p);
  return 0;
}  */
/*
int main(){

   int a[8] = {92, 85, 75, 88, 79, 54, 34, 96};
   int *ap;
   ap = a;
   //printf("%d\n", a[1]);
   //printf("%d\n", *(a+2));
   //ap++;
   //printf("%d\n", ap[1]);
   //printf("%d\n", *(ap+2));
   // a++;
   //printf("%d\n", a[1]);
   while (ap <= &a[7]){
     printf("\n%d", *ap);
     ap++;
   }
   //ap++
   //printf("%d\n", *ap);

   return 0;

} */
/*
int main(){

   int n = 5, *p, **p2, ***p3;
   p = &n;
   //p2 = &p;
   p2 = &n;
   p3 = &p;
   //printf("\n%d \n%d \n%d", n, *p, **p2);
   //printf("\n%d \n%d \n%d", &n, p, *p2);
   printf("\n%d \n%d \n%d", &n, p2, *p3);

  return 0;
}  */
/*
int main(){

  int *ptr, *tmp;
  int n, i, val;

  //n = 5;
  printf("Enter number of integer elements:");
  scanf("%d",&n); 

  ptr = (int*)malloc(n * sizeof(int));

  if (ptr == NULL){

    printf("Memory not allocated. \n");
    exit(0);
  }

  else{

    printf("Memory successfully allcated using malloc.\n");

  

  // get the elements of the array
  tmp = ptr;
  for( i = 0; i < n; i++){
    printf("\nEnter the %d th value please :", i+1);
    scanf("%d", &val);
    *tmp = val;
    tmp++;
  }
  
  tmp = ptr;    // see without wrriting this line 
  printf("The elements of the memory are: ");
  for (i =0; i < n; i++){         // ++i works??
    printf("\n%d, %d", *tmp, ptr[i]);
    tmp++;
  }
  }
  return 0;
} */
/*

typedef union 
{
  // defining a union
  char name[32];
  float salary;
  int wid;                          //       int workerNo;

}unionJob;

typedef struct structJob
{     char name[32];
      float salary;
      int workerNo;
      unionJob test;
  
}sJob;

typedef union{

  // defining a union
  char initials[32];
  float sal;
  sJob test2;
}testunion;

int main(){

unionJob uJob, u2;    // unionJob uJob[5];    
sJob stex;
testunion stwun;
printf("size of union = %d bytes", sizeof(uJob));
printf("\nsize of structure = %d bytes", sizeof(stex));
printf("\nsize of union = %d bytes", sizeof(stwun));
printf("\nsize of data rtypes = %d, %d bytes", sizeof(int), sizeof(float));

uJob.wid = 100;
printf("\n Wid = %d", uJob.wid);
strcpy(uJob.name, "Charles");
printf("\n Wid = %d", uJob.wid);
printf("\n Name = %s", uJob.name);

strcpy(u2.name, "Chaplin");
printf("\n\n\n Name = %s", u2.name);
u2.salary = 100.0;
printf("\n Salary = %f", u2.salary);
printf("\n Name = %s", u2.name);

  return 0;
}
*/
/*
int main(){

  char st1[5] = "Hi", st2[10];
  int i;
  printf("\nThe size of st1 is %d: ", sizeof(st1));
  printf("\nEnter the string to be copied: ");
  scanf("%s", st2);
  printf("\nThe length of the accepted string is %d ", strlen(st2));
  strcpy(st1, st2);
  printf("\n The copied string is : %s ", st1);
  printf("\n The size of st1 is %d: ", sizeof(st1));
  for(i = 0; i < strlen(st1); i++){
    printf("\n%c", st1[i]);
  }

  return 0;
} 
*/

void charcount(char *st, int freq[]){

   int i, counter;
   char ttmp;

   for(i = 0; i < 26; i++)
   {
     freq[i] = 0;
   }

   for (counter = 0; st[counter] != '\0'; counter++)
   {
       
       if(isalpha(st[counter]))
       {

         ttmp = tolower(st[counter]);
         freq[ttmp - 'a']++;
       }


   }
  // for (i = 0; i <26; i++)
  // {
  //  printf("\n %c \t %d", 'a' + i, freq[i]);
  // }
}

int main(){

 char inpstr[30]="apple";
 int i, hfreq[26];
 //printf("Enter the string please:");
 //gets(inpstr);
 charcount(inpstr, hfreq);
 for (i = 0; i <26; i++)
 {

 printf("\n %c \t %d", 'a' + i, hfreq[i]);

 }
   
}  
/*
int extractint(char *str, int vari[]){

   int i, counter = 0, valid = 0;
   char ttmp[5];

   for (i = 0; str[i] != '\0'; i++){

     if ((str[i] >= '0') && (str[i] <= '9')){
       ttmp[counter++] = str[i];
     }

     else {
          
          if ((str[i] == ',') || (str[i] == ';')){

            ttmp[counter] = '\0';
            vari[valid] = atoi(ttmp);
            counter = 0;
            valid++;
          }

     }
   }
     return valid;
     // printf("The total number of valid numbers are %d and they are :", valid);
}

int main(){

  char inp[20] = "int 34,5,  56,";
  int vartable[15], total, i;
  //printf("Enter the string please");
  //gets(inp);
  total = extractint(inp, vartable);
  printf("\n The total number of valid numbers are %d and they are :", total);
  for (i = 0; i<total; i++){
    printf("\n %d", vartable[i]);
  }

  return 0;
} */
/*
char str[100], sub[100];
int count = 0, count1 = 0;
 
void main()
{
    int i, j, l, l1, l2;
 
    printf("\nEnter a string : ");
    scanf("%[^\n]s", str);
 
    l1 = strlen(str);
 
    printf("\nEnter a substring : ");
    scanf(" %[^\n]s", sub);
 
    l2 = strlen(sub);
 
    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    }    
    printf("%s occurs %d times in %s", sub, count1, str);

}
   */

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node
{
 int data;
 struct node *next;
}*head,*new,*trav,*tptr;

void insert_at_begning(int value)
{
 new=(struct node *)malloc(sizeof (struct node));
 new->data=value;

 if(head==NULL)
 {
 head=new;
 head->next=NULL;
 tptr = new;
 }
 else
 {
 new->next=head;
 head=new;
 tptr->next = head;
 }
}


void insert_at_end(int value)
{
 new=(struct node *)malloc(sizeof (struct node));
 new->data=value;
 new->next = NULL;
 
 if(head == NULL)
 {
   head = new;
   new->next = head;  //FOR CIRCULAR LINK

   tptr = new;
 }
 else
 {
   tptr->next = new;
   new->next = head;  // FOR CIRCULAR LINK
   tptr = new;
 }
}


void insert_at_middle(int value, int loc)
{
 struct node *var2,*temp;

 new=(struct node *)malloc(sizeof (struct node));
 new->data=value;

 temp=head;

 if(head==NULL)
 {
 head=new;
 head->next=NULL;
 }
 else
 {
 while(temp->data!=loc)
 {
 temp=temp->next;
 }
 new->next = temp->next;
 temp->next = new;
 }
}


int delete_of_data(int value)
{ 
 struct node *temp,*var;
 temp=head;
 do
 {
 if(temp->data == value)
 {
 if(temp==head)
 {
 head=temp->next;
 tptr->next = temp->next;
 free(temp);
 return 0;
 }
 else
 {
   if(temp->next == head)
   {
     tptr = var; //.........
   }
 var->next=temp->next;
 free(temp);
 return 0;
 }
 }
 else
 {
 var=temp;
 temp=temp->next;
 }
 }while(temp != head); 
printf("data deleted from list is %d",value);
}


int delete_from_end()
{
 struct node *temp, *var;
 temp=head;

 do
 {
    if(temp->next == head)
   {
     tptr = var;
     var->next=temp->next;
     free(temp);
     return 0;//.........
   }
    var=temp;
    temp=temp->next;
    

 }while(temp != head);

 
 }


void display()
{
 trav=head;
 if(trav==NULL)
 {
 printf("\nList is Empty\n");
 }
 else
 {
 printf("\nElements in the List: ");

 do{  
  printf("--> %d ", trav->data);  
  trav = trav->next;  
 }while(trav != head);  
 printf("\n\n");
 }
}
int main()
{
 int i=0;
 head=NULL;

 while(i != 6)
 {
 printf("\ninsertion at begning of linked list - 1");
 printf("\ninsertion at the middle of linked list - 2");
 printf("\ninsertion at the end of linked list - 3");
 printf("\ndeletion from the end of linked list - 4");
 printf("\ndeletion of the data that you want - 5");
 printf("\nexit - 6\n");
   
 printf("\nenter the choice of operation to perform on linked list:   ");
 scanf("%d",&i);

 switch(i)
 {
 case 1:
 {
 int value;

 printf("\nenter the value to be inserted:  ");
 scanf("%d",&value);

 insert_at_begning(value);
 display();
 break;
 }


 case 2:
 {
 int value,loc;

 printf("\nenter the value to be inserted and location:  ");
 scanf("%d%d",&value,&loc);

 insert_at_middle(value,loc);
 display();
 break;
}


 case 3:
 {
 int value;
 printf("\nenter value to be inserted at the end:  ");
 scanf("%d",&value);

 insert_at_end(value);
 display();
 break;
 }


 case 4:
 {
 delete_from_end();
 display();
 break;
 }


 case 5:
 {
 int value;

 display();
 printf("\nenter the data that you want to delete from the list shown above:  ");
 scanf("%d",&value);

 delete_of_data(value);
 display();
 break;
 }

 
 

 }
 }
getch();
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 int data;
 struct node *next;
}*head,*new,*trav,*tptr;

void insert_at_begning(int value)
{
 new=(struct node *)malloc(sizeof (struct node));
 new->data=value;

 if(head==NULL)
 {
 head=new;
 head->next=NULL;
 tptr = new;
 }
 else
 {
 new->next=head;
 head=new;
 tptr->next = head;
 }
}


void insert_at_end(int value)
{
 new=(struct node *)malloc(sizeof (struct node));
 new->data=value;
 new->next = NULL;
 
 if(head == NULL)
 {
   head = new;
   new->next = head;  //FOR CIRCULAR LINK

   tptr = new;
 }
 else
 {
   tptr->next = new;
   new->next = head;  // FOR CIRCULAR LINK
   tptr = new;
 }
}


void insert_at_middle(int value, int loc)
{
 struct node *var2,*temp;

 new=(struct node *)malloc(sizeof (struct node));
 new->data=value;

 temp=head;

 if(head==NULL)
 {
 head=new;
 head->next=NULL;
 }
 else
 {
 while(temp->data!=loc)
 {
 temp=temp->next;
 }
 new->next = temp->next;
 temp->next = new;
 }
}


int delete_of_data(int value)
{ 
 struct node *temp,*var;
 temp=head;
 do
 {
 if(temp->data == value)
 {
 if(temp==head)
 {
 head=temp->next;
 tptr->next = temp->next;
 free(temp);
 return 0;
 }
 else
 {
   if(temp->next == head)
   {
     tptr = var; //.........
   }
 var->next=temp->next;
 free(temp);
 return 0;
 }
 }
 else
 {
 var=temp;
 temp=temp->next;
 }
 }while(temp != head); 
printf("data deleted from list is %d",value);
}


int delete_from_end()
{
 struct node *temp, *var;
 temp=head;

 do
 {
    if(temp->next == head)
   {
     tptr = var;
     var->next=temp->next;
     free(temp);
     return 0;//.........
   }
    var=temp;
    temp=temp->next;
    

 }while(temp != head);

 
 }


void display()
{
 trav=head;
 if(trav==NULL)
 {
 printf("\nList is Empty\n");
 }
 else
 {
 printf("\nElements in the List: ");

 do{  
  printf("--> %d ", trav->data);  
  trav = trav->next;  
 }while(trav != head);  
 printf("\n\n");
 }
}
int main()
{
 int i=0;
 head=NULL;
 insert_at_begning(2);
 insert_at_end(3);
 insert_at_begning(5);
 insert_at_end(7);
 insert_at_begning(6);
 delete_from_end();
 delete_of_data(5);
 insert_at_end(9);
 insert_at_end(99);
display();
 return 0;
 }
 */



 

 
  

  