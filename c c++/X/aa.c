/*#include<stdio.h>
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
        case 'F':
            return 0;
        case 'E':
            return 1;
        case 'D':
            return 2;
        case 'C':
            return 3;
        case 'B':
            return 4;
        case 'A':
            return 5;
        case 'S':
            return 6;

    }

}
int main()
{
    int n,i;
    printf("Enter the number of students:");
    scanf("%d",&n);
    struct details obj[n];

    printf("Enter the details:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the name and grade:");
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

//  C Menu Driven Program for Bubble Selection Insertion Sort  
/*
#include<stdio.h>
#include<stdlib.h>

void display(int a[],int n);
void bubble_sort(int a[],int n);
void selection_sort(int a[],int n);
void insertion_sort(int a[],int n);

//-----------------Main Function----------------------

int main()
{
   int n,choice,i;
   char ch[20];
   printf("Enter no. of elements u want to sort : ");
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

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Display Array.\n5. Exit the Program.\n");
    printf("\nEnter your Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        bubble_sort(arr,n);
        break;
    case 2:
        selection_sort(arr,n);
        break;
    case 3:
        insertion_sort(arr,n);
        break;
    case 4:

        display(arr,n);
        break;

    case 5:
        return 0;
    default:
        printf("\nPlease Select only 1-5 option ----\n");
    }
}
return 0;
}

//-----------End of main function---------------------

//-------------------Display Function-----------------

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
   {
        printf(" %d ",arr[i]);
   }

}

//---------------------Bubble Sort Function-----------

void bubble_sort(int arr[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n-i-1;j++)
      {
          if(arr[j]>arr[j+1])
          {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
          }
      }
  }
printf("After Bubble sort Elements are : ");
display(arr,n);
}

//------------------Selection Sort Function---------

void selection_sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
            }
        }

    }
printf("After Selection sort Elements are : ");
display(arr,n);
}

//---------------Insertion Sort Function-------------------

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
printf("After Insertion sort Elements are : ");
display(arr,n);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);
void mergeSort(int[], int, int);

int main() {
	int n, arr[100];
	int i;
	int op, cont;
	do {
		printf("Enter size of array: ");
		scanf("%d", &n);
		printf("Enter values of array:\n");
		for(i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printf("Enter sorting algorithm to use:\n1: Bubble\n2: Insertion\n3: Quick sort\n4: Merge sort\n");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				bubbleSort(arr, n);
				break;
			case 2:
				insertionSort(arr, n);
				break;
			case 3:
				quickSort(arr, 0, n - 1);
				break;
			case 4:
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

void bubbleSort(int arr[], int size) {
	int i, j, temp;
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				//swap
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void insertionSort(int arr[], int size) {
	int i, j, key;
	for(i = 1; i < size; i++) {
		key = arr[i];
		for(j = i; j > 0 && arr[j - 1] > key; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = key;
	}
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
