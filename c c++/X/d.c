/*
// 2. C Menu Driven Program for Insertion Sort  

#include<stdio.h>
#include<stdlib.h>

void display(int a[],int n);

void insertion_sort(int a[],int n);

//-----------------Main Function----------------------

int main()
{
   int n,choice,i;
   char ch[20];
   printf("Enter the size of stack : ");
   scanf("%d",&n);
   int arr[n];
   for(i=0;i<n;i++)
   {
        printf("Enter %d Element : ",i+1);
        scanf("%d",&arr[i]);
   }
   printf("Please select any option Given Below for Sorting : \n");

while(1)
   {

    printf("\n1. Insertion Sort\n2. Display the stack.\n3. Exit the Program.\n");
    printf("\nEnter your Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        insertion_sort(arr,n);
        break;
    case 2:

        display(arr,n);
        break;

    case 3:
        return 0;
    default:
        printf("\nPlease Select only 1-3 option ----\n");
    }
}
return 0;
}


void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
   {
        printf(" %d ",arr[i]);
   }

}


//--Insertion Sort Function--

void insertion_sort(int arr[],int n)
{
    int i,j,min;
    for(i=1;i<n;i++)
    {
        min=arr[i];
        j=i-1;
        while(min<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=min;
    }
printf("After Insertion sort the given stack is : ");
display(arr,n);
}

/*   
//  qUICK SORT      AND      MERGE SORT
#include <stdio.h>
#include <stdlib.h>


void quickSort(int[], int, int);
void mergeSort(int[], int, int);

int main() {
	int n, arr[100];
	int i;
	int op, cont;
	do {
		printf("Enter size ofstack: ");
		scanf("%d", &n);
		printf("Enter values of stack:\n");
		for(i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printf("Enter sorting algorithm to use:\n1: Quick sort\n 2: Merge sort\n");
		scanf("%d", &op);
		
		switch(op) 
        {
			case 1:
				quickSort(arr, 0, n - 1);
				break;
			case 2:
				mergeSort(arr, 0, n - 1);
				break;
			default:
				printf("Invalid option!");
		}
		for(i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\nContinue? 1/0:\t");
		scanf("%d", &cont);
	} while(cont == 1);
	
	return 0;
}


int partition(int arr[], int offset, int size) {
	int x = arr[size];
	int i = offset - 1;
	int j;
	int temp;
	for(j = offset; j < size; j++) {
		if (arr[j] <= x) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[size];
	arr[size] = temp;
	return i + 1;
}

void quickSort(int arr[], int offset, int size) {
	int pivot;
	if (offset < size) {
		pivot = partition(arr, offset, size);
		quickSort(arr, offset, pivot - 1);
		quickSort(arr, pivot + 1, size);
	}
}

void merge(int arr[], int offset, int mid, int size) {
	int n1 = mid - offset + 1;
	int n2 = size - mid;
	int* l = (int*)calloc(n1 + 1, sizeof(int));
	int* r = (int*)calloc(n2 + 1, sizeof(int));
	int i, j, k;
	for(i = 0; i < n1; i++) {
		*(l + i) = arr[offset + i];
	}
	for(j = 0; j < n2; j++) {
		*(r + j) = arr[mid + j + 1];
	}
	*(l + n1) = 32767;
	*(r + n2) = 32767;
	i = j = 0;
	for(k = offset; k <= size; k++) {
		if(*(l + i) <= *(r + j)) {
			arr[k] = *(l + i);
			i++;
		}
		else {
			arr[k] = *(r + j);
			j++;
		}
	}
	free(l);
	free(r);
}

void mergeSort(int arr[], int offset, int size) {
	if (offset < size) {
		int mid = (offset + size) / 2;
		mergeSort(arr, offset, mid);
		mergeSort(arr, mid + 1, size);
		merge(arr, offset, mid, size);
	}
}
*/

//  QUESTION NO 4
#include<stdlib.h>
#include <stdio.h>
void display();
void insert();

void selection_Sort();
struct node
{
        int data;
        struct node *next;
};
struct node *start=NULL;
int main()     
{
        int n,i;
        printf("Enter the size of the Linked List:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
        	int m;
        	printf("Enter the Element of the linked List:");
        	scanf("%d",&m);
        	insert(m);
		}
		printf("\n");
		printf("Before sort The Element in the linked List:\n");
		display();
        selection_Sort(start);
        printf("After sort The Element in the linked List:\n");
        display();
        
        return 0;
}

void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("List is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                
                while(ptr!=NULL)
                {
                        printf("%d\n",ptr->data );
                        ptr=ptr->next ;
                }
        }
}

void insert(int x)
{
        struct node *temp,*ptr;
        
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
        
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}

void selection_Sort(struct node* head)
{
    struct node* temp = head;
  
    // Traverse the List
    while (temp) {
        struct node* min = temp;
        struct node* r = temp->next;
  
        // Traverse the unsorted sublist
        while (r) {
            if (min->data > r->data)
                min = r;
  
            r = r->next;
        }
  
        // Swap Data
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}

/*
//  Q NO 1.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 20
struct details{

    char name[max];
    char grade;
};

int prio(char ch)
{
    switch(ch)
    {
        case 'S':
            return 0;
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        case 'D':
            return 4;
        case 'E':
            return 5;
        case 'F':
            return 6;

    }

}
int main()
{
    int n,i;
    printf("Enter the number of students: \n");
    scanf("%d",&n);
    struct details obj[n];

    printf("Enter the details:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the name and grade: \n");
        scanf("%s %c",obj[i].name,&obj[i].grade);

    }
    char temp2[100];
    int temp,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(prio(obj[j].grade)>prio(obj[j+1].grade))
            {
                strcpy(temp2,obj[j].name);
                temp=obj[j].grade;
                strcpy(obj[j].name,obj[j+1].name);
                obj[j].grade=obj[j+1].grade;
                strcpy(obj[j+1].name,temp2);
                obj[j+1].grade=temp;
            }

        }
    }
    printf("\nThe details are:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %c",obj[i].name,obj[i].grade);
        printf("\n");
    }


    return 0;
}
*/
/*
#include <stdio.h>
#include<stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
void quicksort(int number[],int first,int last);

int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
{
    printf("1.Insert element to queue n");
    printf("2.Delete element from queue n");
    printf("3.Display sorted queue n");
    printf("4.Quit n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice n");
        }
    }
}
void insert()
{
    int item;
    if(rear == MAX - 1)
    printf("Queue Overflow n");
    else
    {
        if(front== - 1)
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_array[rear] = item;
    }
}
void delete()
{
    if(front == - 1 || front > rear)
    {
        printf("Queue Underflow n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %dn", queue_array[front]);
        front = front + 1;
    }
}

void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

void display()
{
    int i;
    if(front == - 1)
    printf("Queue is empty n");
    else
    {
        printf("Queue is : n");
        quicksort(queue_array,queue_array[front],queue_array[rear]);
        for(i = front; i <= rear; i++)
        printf("%d ", queue_array[i]);
        printf("n");
    }
}
*/