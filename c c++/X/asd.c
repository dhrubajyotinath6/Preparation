// qno 3
#include <stdio.h>
#include<stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
void quick_sort();
void merge_sort();

int queue_array[MAX];
int rear = - 1;
int front = - 1;

void quicksort(int number[50],int first,int last){
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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int choice;
    while (1)
{
    printf("\n\n\n1.Insert element to queue :\n");
    printf("2.Delete element from queue :\n");
    printf("3.Use quick sort :\n");
    printf("4.use merge sort: \n");
    printf("5.Quit \n");
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
            quick_sort();
            break;
        case 4:
            merge_sort();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice \n");
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
        printf("Insert the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_array[rear] = item;
    }
}
void delete()
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


void quick_sort()
{
    int i;
    if(front == - 1)
    printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        quicksort (queue_array,front,rear);
        for(i = front; i <= rear; i++)
        printf("%d ", queue_array[i]);
        printf("\n");
    }
}

void merge_sort()
{
    int i;
    if(front == - 1)
    printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        mergeSort(queue_array,front,rear);
        for(i = front; i <= rear; i++)
        printf("%d ", queue_array[i]);
        printf("\n");
    }
}