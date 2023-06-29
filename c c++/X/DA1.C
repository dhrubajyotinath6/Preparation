// 20BCE0038
// DHRUBA JYOTI NATH
//DSA L11+12 
/*
#include<stdio.h>             //c program to implement a stack using array
int stack[100],choice,n,top,x,i;
void push(void);    
void pop(void);
void display(void);
int main()
{
    //clrscr();
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
        {
           printf("\n%d",stack[i]);
        }
            
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
*/
/*
#include<stdio.h>     // C Program to Convert Infix to Postfix using Stack
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)  
        return -1;       
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;            
    if(x == '*' || x == '/')
        return 2;        
    return 0;
}

int main()

{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))   
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x == pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
*/
/*
#include<stdio.h>
#include<ctype.h>
int stack[20];   // C Program to Evaluate POSTFIX Expression Using Stack
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression :: ");  
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
*/
/*
#include <stdio.h>  // C Program to Check if Expression is correctly Parenthesized
#include <stdlib.h>   
#include <string.h>
 
int top = -1;
char stack[100];
 
// function prototypes
void push(char);
void pop();
void find_top();
 
int main()
{
    int i;
    char a[100];
    printf("enter expression\n");
    scanf("%s", &a);
    for (i = 0; a[i] != '\0';i++)
    {
        if (a[i] == '(')
        {
            push(a[i]);
        }
        else if (a[i] == ')')
        {
            pop();
        }
    }
    find_top();
}
 
// to push elements in stack
void push(char a)
{
    top++;
    stack[top] = a;   
}
 
// to pop elements from stack
void pop()
{
    if (top == -1)
    {
        printf("expression is invalid\n");
        exit(0);
    }   
    else
    {       
        top--;
    }
}
 
// to find top element of stack
void find_top()
{
    if (top == -1)
        printf("\nexpression is valid\n");
    else
        printf("\nexpression is invalid\n");
}
*/
/*
#include <stdio.h> // C Program to Check String is Palindrome using Stack
#include <stdlib.h>
#include <string.h>
#define MAX 50
 
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
 
int main()
{
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("1-enter string\n2-exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            scanf("%s", s);
            for (i = 0;s[i] != '\0';i++)
            {
                b = s[i];
                push(b);
            }
            for (i = 0;i < (strlen(s) / 2);i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break; 
                }
            }
            if ((strlen(s) / 2)  == front)
                printf("%s is palindrome\n",  s);
            front  =  0;
            top  =  -1;
            break;
        case 2:
            exit(0);
        default:
            printf("enter correct choice\n");
        }
    }
    return 0;
}
 
// to push a character into stack 
void push(char a)
{
    top++;
    stack[top]  =  a;
}
 
// to delete an element in stack
void pop()
{
    top--;
}
*/
/*
#include<stdio.h>   // C program to Reverse a Number using STACK
#include<stdlib.h>
#include<string.h>
#define MAX 5
char stack[MAX];
void push(char);
int top =-1;


void push(char C)
{
    top = top + 1;
    stack[top] = C;
}

int main()
{
    int i,n;
    char str[50];
    printf("ENTER THE NUMBER: ");
    scanf("%s",str);
    
    for(n=0;n<MAX;n++)
    {
        push(str[n]);
    }

    for(i=(MAX-1);i>=0;i--)
    {
        printf("%c",stack[top]);
        top = top - 1;
    }
}
*/

/*
#include <stdio.h>       // 1. Write a program to implement a queue using arrays
#include<stdlib.h>      
#define MAX 50
void insert();
void delete_();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
printf("Queue  \n");
int choice;
while (1)                   
{
printf("\n\n\n1. insertion\n");
printf("2. deletion\n");
printf("3. display all elements\n");
printf("4. quit\n");
printf("which operation : \n");
scanf("%d", &choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
delete_();
break;
case 3:
display();
break;
case 4:
exit(1);             
default:
printf("Wrong choice \n");
}
}
return 0;
}
void insert()
{
int item;
if(rear == MAX - 1)
printf("Queue Overflow \n");
else
{
if(front== - 1)
{
   front = 0;
}
printf("Inset the element in queue : \n");
scanf("%d", &item);
rear = rear + 1;
queue_array[rear] = item;
}
}
void delete_()
{
if(front == - 1 || front > rear)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("Element deleted from queue is : %d\n", queue_array[front]);
front = front + 1;
}
}
void display()
{
int i;
if(front == - 1)
printf("Queue is empty \n");
else
{
printf("Queue is : \n");
for(i = front; i <= rear; i++)
{
    printf("%d ", queue_array[i]);
}

printf("\n");
}
} 
*/
/*
#include <stdio.h>    //write a program to count the total no of elements in queue
#include<stdlib.h>   
#define MAX 50
void insert();
void delete_();
void display();
void number();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int no;
int main()
{
printf("Queue  \n");
int choice;
while (1)
{
printf("\n\n\n1. insertion\n");
printf("2. deletion\n");
printf("3. display all elements\n");
printf("4. no of elements in queue\n");
printf("5. quit\n");
printf("which operation : \n");
scanf("%d", &choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
delete_();
break;
case 3:
display();
break;
case 4:
number();
break;
case 5:
exit(1);
default:
printf("Wrong choice n\n");
}
}
}
void insert()
{
int item;
if(rear == MAX - 1)
printf("Queue Overflow \n");
else
{
if(front== - 1)
front = 0;
printf("Inset the element in queue : \n");
scanf("%d", &item);
rear = rear + 1;
queue_array[rear] = item;
}
}
void delete_()
{
if(front == - 1 || front > rear)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("Element deleted from queue is : %d\n", queue_array[front]);
front = front + 1;
}
}
void number(){
    
    no = rear - front +1;
    printf("Total no of elements %d",no);
}
void display()
{
int i;
if(front == - 1 || front > rear){
    printf("Queue is empty \n");
}
else
{
printf("Queue is : \n");
for(i = front; i <= rear; i++)
printf("%d ", queue_array[i]);
printf("\n");
}
}
*/
/*
#include <stdio.h>  //Write a program to implement a circular queue.

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  deQueue();
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
  enQueue(6);
  display();
  deQueue();
  display();
  enQueue(7);
  display();
  enQueue(8);
  return 0;
} 
*/
// Write a program to implement a DEQueue.
 

#include<stdio.h>
#include<conio.h>
#define MAX 10

int deque[MAX];
int left=-1, right=-1;

void insert_right(void);
void insert_left(void);
void delete_right(void);
void delete_left(void);
void display(void);

int main()
{
 int choice;
 
 do
 {
  printf("\n1.Insert at right ");
  printf("\n2.Insert at left ");
  printf("\n3.Delete from right ");
  printf("\n4.Delete from left ");
  printf("\n5.Display ");
  printf("\n6.Exit");
  printf("\n\nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    insert_right();
    break;
   case 2:
    insert_left();
    break;
   case 3:
    delete_right();
    break;
   case 4:
    delete_left();
    break;
   case 5:
    display();
    break;
  }
 }while(choice!=6);
 getch();
 return 0;
}

void insert_right()
{
 int val;
 printf("\nEnter the value to be added ");
 scanf("%d",&val);
 if( (left==0 && right==MAX-1) || (left==right+1) )
 {
  printf("\nOVERFLOW");
 }
 if(left==-1)       
 {
  left=0;
  right=0;
 }
 else
 {
  if(right==MAX-1)
   right=0;
  else
   right=right+1;
 }
 deque[right]=val;
}

void insert_left()
{
 int val;
 printf("\nEnter the value to be added ");
 scanf("%d",&val);
 if( (left==0 && right==MAX-1) || (left==right+1) )
 {
  printf("\nOVERFLOW");
 }
 if(left==-1)      
 {
  left=0;
  right=0;
 }
 else
 {
  if(left==0)
   left=MAX-1;
  else
   left=left-1;
 }
 deque[left]=val;
}

void delete_right()
{
 if(left==-1)
 {
  printf("\nUNDERFLOW");
  return;
 }
 printf("\nThe deleted element is %d\n", deque[right]);
 if(left==right)          
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(right==0)
   right=MAX-1;
  else
   right=right-1;
 }
}


void delete_left()
{
 if(left==-1)
 {
  printf("\nUNDERFLOW");
  return;
 }
 printf("\nThe deleted element is %d\n", deque[left]);
 if(left==right)          
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(left==MAX-1)
   left=0;
  else
   left=left+1;
 }
}

//-------DISPLAY-------
void display()
{
 int front=left, rear=right;
 if(front==-1)
 {
  printf("\nQueue is Empty\n");
  return;
 }
 printf("\nThe elements in the queue are: ");
 if(front<=rear)
 {
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 else
 {
  while(front<=MAX-1)
  {
   printf("%d\t",deque[front]);
   front++;
  }
  front=0;
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 printf("\n");
} 
/*
// Write a program to input two queues and compare their contents.
#include<stdio.h>
int A[10],B[10],front1=-1,rear1=0,counter1=0,front2=-1,rear2=0,counter2=0;
int isempty()
{
    if(counter1==0)
        return 0;
    else
        return 1;
}
int isfull()
{
    if(counter1==10)
        return 0;
    else
        return 1;
}
void enqueue(int x)
{
    int a=isfull();
    if(a==0)
        printf("Queue is Full");
    else
    {
        A[rear1++]=x;
        counter1++;
    }
}
int dequeue()
{
    int a=isempty();
    if(a==0)
    {
        printf("Queue is Empty");
        return -999;
    }
    else
    {
        counter1--;
        return A[++front1];
    }
}
int isempty1()
{
    if(counter2==0)
        return 0;
    else
        return 1;
}
int isfull1()
{
    if(counter2==10)
        return 0;
    else
        return 1;
}
void enqueue1(int x)
{
    int a=isfull();
    if(a==0)
        printf("Queue is Full");
    else
    {
        B[rear2++]=x;
        counter2++;
    }
}
int dequeue1()
{
    int a=isempty();
    if(a==0)
    {
        printf("Queue is Empty");
        return -999;
    }
    else
    {
        counter2--;
        return B[++front2];
    }
}
void displayqueue()
{
    if(counter1==0)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Left Over Queue-\n");
    for(int i=front1;i<rear1-1;i++)
        printf("%d\n",A[(i+1)]);
    }
}
void displayqueue1()
{
    if(counter2==0)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Left Over Queue-\n");
    for(int i=front2;i<rear2-1;i++)
        printf("%d\n",B[(i+1)]);
    }
}
int count()
{
    int c=0;
    if(counter1==0)
        printf("Queue is Empty\n");
    else
    {
        for(int i=front1;i<rear1-1;i++)
        c++;
    }
    return c;
}
int count1()
{
    int c=0;
    if(counter2==0)
        printf("Queue is Empty\n");
    else
    {
        for(int i=front2;i<rear2-1;i++)
        c++;
    }
    return c;
}
void compare()
{
    int f=-1;
    if(counter1==counter2)
    {
        for(int i=front1+1;i<rear1;i++)
            if(A[i]!=B[i])
            {
                f=0;
                break;
            }
    }
    else
        f=0;
    if(f==-1)
        printf("Similar Queues");
    else
        printf("Not Similar Queues");
}
int main()
{
    enqueue(15);
    enqueue(17);
    enqueue(18);
    enqueue(19);
    enqueue1(16);
    enqueue1(17);
    enqueue1(18);
    enqueue1(19);
    compare();
    int a=dequeue();
    printf("%d\n",a);
    int x=dequeue1();
    printf("%d\n",x);
    compare();
}

// Write a program to implement a queue using arrays which permits insertion at both the ends.
# include<stdio.h>  
# define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

void insert_right()
{
    int added_item;
    if((left == 0 && right == MAX-1) || (left == right+1))
    {   printf("Queue Overflow\n");
        return;}
    if (left == -1)   
    {   left = 0;
        right = 0;}
    else
    if(right == MAX-1)  
        right = 0;
    else
        right = right+1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[right] = added_item ;
}

void insert_left()
{   int added_item;
    if((left == 0 && right == MAX-1) || (left == right+1))
    {   printf("Queue Overflow \n");
        return;  }
    if (left == -1)
    {   left = 0;
        right = 0;   }
    else
    if(left== 0)
        left=MAX-1;
    else
        left=left-1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[left] = added_item ;   }

void delete_left()
{   if (left == -1)
    {   printf("Queue Underflow\n");
        return ;    }
    printf("Element deleted from queue is : %d\n",deque_arr[left]);
    if(left == right)  
    {   left = -1;
        right=-1;    }
    else
        if(left == MAX-1)
            left = 0;
        else
            left = left+1;
}


void delete_right()
{if (left == -1)
    {printf("Queue Underflow\n");
        return ;     }
    printf("Element deleted from queue is : %d\n",deque_arr[right]);
    if(left == right) 
    {   left = -1;
        right=-1;    }
    else
        if(right == 0)
            right=MAX-1;
        else
            right=right-1;  }

void display_queue()
{   int front_pos = left,rear_pos = right;
    if(left == -1)
    {   printf("Queue is empty\n");
        return;  }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos )
    {   while(front_pos <= rear_pos)
        {   printf("%d ",deque_arr[front_pos]);
            front_pos++;    }   }
    else
    {   while(front_pos <= MAX-1)
        {   printf("%d ",deque_arr[front_pos]);
            front_pos++;    }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {   printf("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

void output_que()
{   int choice;
    do
    {   printf("1.Insert at right\n");
        printf("2.Insert at left\n");
        printf("3.Delete from left\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
            insert_right();
            break;
         case 2:
            insert_left();
            break;
         case 3:
            delete_left();
            break;
         case 4:
            display_queue();
            break;
         case 5:
            break;
         default:
            printf("Wrong choice\n");
        }
    }while(choice!=5);
}

int main()
{   
    
    output_que();
        
}
*/