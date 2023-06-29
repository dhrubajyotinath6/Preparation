//Linear search program in C
/*
#include <stdio.h>
int main()
{
  int array[100], search, c, n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d integer(s)\n", n);

  for (c = 0; c < n; c++){
      scanf("%d", &array[c]);
  }
    

  printf("Enter a number to search\n");
  scanf("%d", &search);

  for (c = 0; c < n; c++)
  {
    if (array[c] == search)    //If required element is found 
    {
      printf("%d is present at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d isn't present in the array.\n", search);

  return 0;
} */

//15. Program to accept a number and print sum of it’s digits.
/*
#include<stdio.h>
#include<conio.h>
void main()
{
    int reminder, sum=0, n;
    //clrscr();

    printf("Enter n : ");
    scanf("%d", &n);

    while(n>0)
    {
        reminder = n % 10;
        sum = sum + reminder;
        n = n / 10;
    }
    printf("Sum of digits : %d",sum);
    getch();
}
*/

//16. Pattern 1
/*
•
• •
• • •
• • • •
• • • • •

#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n;
    clrscr();

    printf("Enter number :");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("• ");
        }
        printf("\n");
    }
    getch();
}
*/

//17. Pattern 2
/*
• • • • •
• • • •
• • •
• •
•

#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n;
    clrscr();

    printf("Enter number : ");
    scanf("%d", &n);

    for(i=n; i>=1; i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("• ");
        }
        printf("\n"); 
    }
    getch();
}
*/

//18. Pattern 3
/*
         •
       • •
     • • •
   • • • •
 • • • • •

#include<stdio.h>
#include<conio.h>

void main()
{
    char ch = '*';
    int n,i, j, no_of_spaces = 0, spaceCount;

    printf("Enter number : ");
    scanf("%d", &n);
    printf("\n");
    no_of_spaces = n - 1;

    for (i = 1; i <= n; i++)
    {
        for (spaceCount = no_of_spaces; spaceCount >= 1; spaceCount--)
        {
            printf("  "); 
        }
        for (j = 1; j <= i; j++)
        {
            printf("%2c", ch);
        }
        printf("\n");
        no_of_spaces--;
    }
    getch();
}
*/

//19. Pattern 5
/*
1
2 1
3 2 1
4 3 2 1
5 4 3 2 1

#include <stdio.h>
#include<conio.h>

void main()
{
    int i, j, n;
    printf("Enter number : ");
    scanf("%d", &n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        for (j = i; j >= 1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    getch();
}
*/

//20. Pattern 6
/*
A
B C
D E F
G H I J
K L M N O

#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n;
    //clrscr();

    printf("Enter number : ");
    scanf("%d", &n);
    int c = 'A';

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%c", c);
            c = c + 1;
        }
        printf("\n");
    }
    getch();
}
*/

//21. Pattern 8 (Binary Pattern)
/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j;
    int count = 1;
    clrscr();

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", count++ % 2);
            if (j == i && i != 5)
                printf("\n");
        }
        if (i % 2 == 0)
            count = 1;
        else
            count = 0;
    }
    getch();
}
*/

//22. Pattern 11
/*
1                   1
1 2             2 1
1 2 3       3 2 1
1 2 3 4 4 3 2 1

#include<stdio.h>
#include<conio.h>
void main()
{
    int i, j, k;
    clrscr();

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            if (j <= i)
            {
                printf("%d ", j);
            }
            else
            {
                printf(" ");
            }
        }
        for (j = 5; j >= 1; j--)
        {
            if (j <= i)
            {
                printf("%d ", j);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    getch();
}
*/

 //~~~~~~~~~~~MATRIX ROTATION~~~~~~~~~~

//1. Matrix rotation by 90° clockwise
/*
#include<stdio.h>
int main() 
{ 
    int i, j, n, m;
    printf("Enter no of rows: ");
    scanf("%d", &n);
    printf("Enter no of columns: ");
    scanf("%d", &m);
    int a[n][m], b[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        { 
            scanf("%d", &a[i][j]);
        }
    }

     printf("Original matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d  ", a[i][j]);

        }
        printf("\n");
    }
    
    for(int i = m-1; i >= 0; i--)
    {
      for(int j = 0; j < n; j++)
        b[j][m-i-1] = a[i][j];
    }
    
    printf("Matrix after 90 clockwise rotation\n");

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++)
           printf("%d ", b[i][j]);
        printf("\n");
    }
    return 0; 
}
*/

//2. Matrix rotation by 90° anticlockwise
/*
#include<stdio.h>
int main() 
{ 
    int i, j, n, m, k, temp;
    printf("Enter no of rows: ");
    scanf("%d", &n);
    printf("Enter no of columns: ");
    scanf("%d", &m);
    int a[n][m], b[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        { 
            scanf("%d", &a[i][j]);
        }
    }

     printf("Original matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d  ", a[i][j]);

        }
        printf("\n");
    }
    
    /transpose/
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        { 
            b[j][i] = a[i][j];
        }
    }
    
    /reverse columns/
    for(i=0; i<n; i++)
    {
        k = n-1;
        for(j=0; j<k; j++)
        {
            temp = b[j][i];
            b[j][i] = b[k][i];
            b[k][i] = temp;
            k--;
        }
    }
    
    printf("Matrix after 90 anticlockwise rotation\n");

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++)
           printf("%d ", b[i][j]);
        printf("\n");
    }
    return 0; 
}
*/
//3. Matrix rotation by 180°
/*
#include<stdio.h>
int main() 
{ 
    int i, j, n, m, k, temp;
    printf("Enter no of rows: ");
    scanf("%d", &n);
    printf("Enter no of columns: ");
    scanf("%d", &m);
    int a[n][m], b[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        { 
            scanf("%d", &a[i][j]);
        }
    }

     printf("Original matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d  ", a[i][j]);

        }
        printf("\n");
    }
    
    printf("Martix after 180 rotation\n");
   for (int i = n - 1; i >= 0; i--) 
   {
        for (int j = n - 1; j >= 0; j--)
            printf("%d ", a[i][j]);
 
        printf("\n");
   }
    return 0; 
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct computers{
      
     char name[20];
     char IP[20];
     char IP1[10];
}Com;


int main()
{   
    int n;

    printf("Enter no of computers: ");
    scanf("%d", &n);

    Com *p;
    p = (Com*)malloc(n*sizeof(Com));

    if (p == NULL)
    {
      printf("Memory not allocated. \n");
      exit(0);
    }

  else
  {
     printf("Memory successfully allcated using malloc.\n\n\n");
     
     for(int i = 0; i < n; i++)
     {
       printf("Enter IP address: ");
       scanf("%s",(p+i)->IP);

       printf("Enter name : ");
       scanf("%s",(p+i)->name );
      
       strncpy((p+i)->IP1, (p+i)->IP, 6);
       (p+i)->IP1[6] = 0;
     }

     printf("Information: \n");
     for(int i = 0; i < n; i++)
     {
         printf("%s   %s   %s\n", (p+i)->name, (p+i)->IP, (p+i)->IP1);
     }

     printf("\n~~~~~~~~~~~~~~~~~\n");

     for (int i = 0; i < n; i++)
     {  
         for(int j = i+1; j < n; j++)
         {
             if (strcmp((p+i)->IP1, (p+j)->IP1) == 0)
             {
                 printf("SAME LOCALITY   %s   %s\n\n", (p+i)->name, (p+j)->name);
             }
         }
         
     }
     
  }
  free(p);
  return 0;
}
*/
    /*
    Com C1;
    strcpy(C1.name, "Atlas");
    strcpy(C1.IP, "101.77.78");
    strncpy(C1.IP1, C1.IP, 3);
    C1.IP1[3] = 0;


    Com C2;
    strcpy(C2.name, "Horizon");
    strcpy(C2.IP, "456.12.34");
    strncpy(C2.IP1, C2.IP, 3);
    C2.IP1[3] = 0;

    Com C3;
    strcpy(C3.name, "Pluto");
    strcpy(C3.IP, "101.67.78");
    strncpy(C3.IP1, C3.IP, 3);
    C3.IP1[3] = 0;

   // printf("%s", C1.IP1);

    if (strcmp(C1.IP1, C2.IP1) == 0)
    {
        printf("SAME LOCALITY %s , %s", C1.name, C2.name);
    }

    if (strcmp(C1.IP1, C3.IP1) == 0)
    {
        printf("SAME LOCALITY %s , %s", C1.name, C3.name);
    }

    if (strcmp(C2.IP1, C3.IP1) == 0)
    {
        printf("SAME LOCALITY %s , %s", C2.name, C3.name);
    }
     */
/*

*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct lib
{
   char regNo[20];
}lib;

int main()
{
    int n;
    char s[20];
    scanf("%d",&n);

    if(n <= 0){
        printf("Invalid input");      
    }

    lib *p;
    p = (lib*)malloc(n*sizeof(lib));

    for(int i = 0; i < n; i++)
    {
       scanf("%s",(p+i)->regNo);
    }
    
    scanf("%s",s);
    lib *tmp;
    tmp = p;
    for(int i = 0; i < n; i++)
    {
        if(strcmp(s,(p+i)->regNo)==0){
            printf("Found");
            return 1;
        }
        else{
            printf("Not found");
            return -1;
        }

    }
   free(p);
    return 0;
}
*/

// Implementing hash table in C
/*
#include <stdio.h>
#include <stdlib.h>

struct set
{
  int key;
  int data;
};
struct set *array;
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
  return (key % capacity);
}
int checkPrime(int n)
{
  int i;
  if (n == 1 || n == 0)
  {
  return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
  if (n % i == 0)
  {
    return 0;
  }
  }
  return 1;
}
int getPrime(int n)
{
  if (n % 2 == 0)
  {
  n++;
  }
  while (!checkPrime(n))
  {
  n += 2;
  }
  return n;
}
void init_array()
{
  capacity = getPrime(capacity);
  array = (struct set *)malloc(capacity * sizeof(struct set));
  for (int i = 0; i < capacity; i++)
  {
  array[i].key = 0;
  array[i].data = 0;
  }
}

void insert(int key, int data)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
  array[index].key = key;
  array[index].data = data;
  size++;
  printf("\n Key (%d) has been inserted \n", key);
  }
  else if (array[index].key == key)
  {
  array[index].data = data;
  }
  else
  {
  printf("\n Collision occured  \n");
  }
}

void remove_element(int key)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
  printf("\n This key does not exist \n");
  }
  else
  {
  array[index].key = 0;
  array[index].data = 0;
  size--;
  printf("\n Key (%d) has been removed \n", key);
  }
}
void display()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
  if (array[i].data == 0)
  {
    printf("\n array[%d]: / ", i);
  }
  else
  {
    printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
  }
  }
}

int size_of_hashtable()
{
  return size;
}

int main()
{
  int choice, key, data, n;
  int c = 0;
  init_array();

  do
  {
  printf("1.Insert item in the Hash Table"
     "\n2.Remove item from the Hash Table"
     "\n3.Check the size of Hash Table"
     "\n4.Display a Hash Table"
     "\n\n Please enter your choice: ");

  scanf("%d", &choice);
  switch (choice)
  {
  case 1:

    printf("Enter key -:\t");
    scanf("%d", &key);
    printf("Enter data -:\t");
    scanf("%d", &data);
    insert(key, data);

    break;

  case 2:

    printf("Enter the key to delete-:");
    scanf("%d", &key);
    remove_element(key);

    break;

  case 3:

    n = size_of_hashtable();
    printf("Size of Hash Table is-:%d\n", n);

    break;

  case 4:

    display();

    break;

  default:

    printf("Invalid Input\n");
  }

  printf("\nDo you want to continue (press 1 for yes): ");
  scanf("%d", &c);

  } while (c == 1);
}
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

// returns the index of the parent node
int parent(int i) {
    return (i - 1) / 2;
}

// return the index of the left child 
int left_child(int i) {
    return 2*i + 1;
}

// return the index of the right child 
int right_child(int i) {
    return 2*i + 2;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// insert the item at the appropriate position
void insert(int a[], int data, int *n) {
    if (*n >= MAX_SIZE) {
        printf("%s\n", "The heap is full. Cannot insert");
        return;
    }
    // first insert the time at the last position of the array 
    // and move it up
    a[*n] = data;
    *n = *n + 1;


    // move up until the heap property satisfies
    int i = *n - 1;
    while (i != 0 && a[parent(i)] < a[i]) {
        swap(&a[parent(i)], &a[i]);
        i = parent(i);
    }
}

// moves the item at position i of array a
// into its appropriate position
void max_heapify(int a[], int i, int n){
    // find left child node
    int left = left_child(i);

    // find right child node
    int right = right_child(i);

    // find the largest among 3 nodes
    int largest = i;

    // check if the left node is larger than the current node
    if (left <= n && a[left] > a[largest]) {
        largest = left;
    }

    // check if the right node is larger than the current node
    if (right <= n && a[right] > a[largest]) {
        largest = right;
    }

    // swap the largest node with the current node 
    // and repeat this process until the current node is larger than 
    // the right and the left node
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }

}

// converts an array into a heap
void build_max_heap(int a[], int n) {
    int i;
    for (i = n/2; i >= 0; i--) {
        max_heapify(a, i, n);
    } 
}

// returns the  maximum item of the heap
int get_max(int a[]) {
    return a[0];
}

// deletes the max item and return
int extract_max(int a[], int *n) {
    int max_item = a[0];

    // replace the first item with the last item
    a[0] = a[*n - 1];
    *n = *n - 1;

    // maintain the heap property by heapifying the 
    // first item
    max_heapify(a, 0, *n);
    return max_item;
}

// prints the heap
void print_heap(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");
}


int main() {
    int n = 10;
    int a[MAX_SIZE];
    a[1] = 10; a[2] = 12; a[3] = 9; a[4] = 78; a[5] = 33; a[6] = 21; a[7] = 35; a[8] = 29; a[9] = 5; a[10] = 66;
    build_max_heap(a, n);
    insert(a, 55, &n);
    insert(a, 56, &n);
    insert(a, 57, &n);
    insert(a, 58, &n);
    insert(a, 100, &n);
    print_heap(a, n);
    return 0;
}