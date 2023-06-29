/*
#include<stdio.h> // 1. Write a program to create a singly linked list and perform insertions and deletions of all cases.
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
}*head,*var,*trav;
void insert_at_begning(int value)
{
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
var->next=head;
head=var;
}
}
void insert_at_end(int value)
{
struct node *temp;
temp=head;
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
var->next=NULL;
temp->next=var;
}
}
int delete_of_data(int value)
{
struct node *temp,*var;
temp=head;
while(temp!=NULL)
{
if(temp->data == value)
{
if(temp==head)
{
head=temp->next;
free(temp);
return 0;
}
else
{
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
}
printf("data deleted from list is %d",value);
}
int delete_from_end()
{
struct node *temp;
temp=head;
while(temp->next != NULL)
{
var=temp;
temp=temp->next;
}
if(temp ==head)
{
head=temp->next;
free(temp);
//printf("Sorry, the list is already empty");
return 0;
}
printf("data deleted from list is %d",temp->data);
var->next=NULL;
free(temp);
return 0;
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
while(trav!=NULL)
{
printf(" -> %d ",trav->data);
trav=trav->next;
}
printf("\n\n");
}
}
int main()
{
int i=0;
head=NULL;
while(1)
{
printf("\ninsertion at begning - 1");
printf("\ninsertion at the end - 2");
printf("\ndeletion from the end - 3");
printf("\ndeletion of the data that you want - 4");
printf("\nexit - 5\n");

printf("\nenter the choice of operation to perform on linked list: ");
scanf("%d",&i);
switch(i)
{
case 1:
{
int value;
printf("\nenter the value to be inserted: ");
scanf("%d",&value);
insert_at_begning(value);
display();
break;
}
case 2:
{
int value;
printf("\nenter value to be inserted at the end: ");
scanf("%d",&value);
insert_at_end(value);
display();
break;
}
case 3:
{
delete_from_end();
display();
break;
}
case 4:
{
int value;
display();
printf("\nenter the data that you want to delete from the list shown above:");

scanf("%d",&value);
delete_of_data(value);
display();
break;
}
case 5:
{
exit(0);
}
}
}
getch();
}

*/

#include <stdio.h> // 2. Write a program to create a circular linked list and perform insertion and deletion at the
#include <stdlib.h> // beginning and end of the list.
#include <conio.h>
#include<string.h>
struct node
{
int info;
struct node* next;
};
struct node* last = NULL;
void insertAtFront()
{
int data;
struct node* temp;
temp = (struct node*)malloc(sizeof(struct node));
printf("\nEnter data to be inserted: \n");
scanf("%d", &data);
if (last == NULL) {
temp->info = data;
temp->next = temp;
last = temp;
}
else
{
temp->info = data;
temp->next = last->next;
last->next = temp;
}
}
void addatlast()
{
int data;
struct node* temp;
temp = (struct node*)malloc(sizeof(struct node));
printf("\nEnter data to be inserted : \n");
scanf("%d", &data);
if (last == NULL) {
temp->info = data;
temp->next = temp;
last = temp;
}
else
{
temp->info = data;
temp->next = last->next;
last->next = temp;
last = temp;
}
}
void deletefirst()
{
struct node* temp;
if (last == NULL)
{
printf("\nList is empty.\n");
}
else
{
temp = last->next;
last->next = temp->next;
free(temp);
}
}
void deletelast()
{
struct node* temp;
if (last == NULL)
{
printf("\nList is empty.\n");
}
temp = last->next;
while (temp->next != last)
{
temp = temp->next;
}
temp->next = last->next;
last = temp;
}
void viewList()
{
if (last == NULL)
{
printf("\nList is empty\n");
}
else
{
struct node* temp;
temp = last->next;
do
{
printf("%d-->", temp->info);
temp = temp->next;
}
while (temp != last->next);
}
}
int main (void)
{
int i = 0;
while(1)
{
printf("\n1. Insertion at begnning of circular linked list.");
printf("\n2. Insertion at the end of circular linked list.");
printf("\n3. Deletion from the beginning of circular linked list");
printf("\n4. Deletion from the end of circular linked list");
printf("\n5. Exit \n");
printf("\nEnter the choice of operation to perform on circular linked list.\n");

scanf("%d",&i);
switch(i)
{
case 1:
{
insertAtFront();
viewList();
break;
}
case 2:
{
addatlast();
viewList();
break;
}
case 3:
{
deletefirst();
viewList();
break;
}
case 4:
{
deletelast();
viewList();
break;
}
case 5:
{
exit(0);
}
}
}
getch();
}


/*

#include<stdio.h> // Develop a code to perform sorting using linked list.
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
}*head,*var,*trav;
void insert_at_begning(int value)
{
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
var->next=head;
head=var;
}
}
void insert_at_end(int value)
{
struct node *temp;
temp=head;
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
var->next=NULL;
temp->next=var;
}
}
int delete_of_data(int value)
{
struct node *temp,*var;
temp=head;
while(temp!=NULL)
{
if(temp->data == value)
{
if(temp==head)
{
head=temp->next;
free(temp);
return 0;
}
else
{
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
}
printf("data deleted from list is %d",value);
}
int delete_from_end()
{
struct node *temp;
temp=head;
while(temp->next != NULL)
{
var=temp;
temp=temp->next;
}
if(temp ==head)
{
head=temp->next;
free(temp);
return 0;
}
printf("data deleted from list is %d",temp->data);
var->next=NULL;
free(temp);
return 0;
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
while(trav!=NULL)
{
printf(" -> %d ",trav->data);
trav=trav->next;
}
printf("\n\n");
}
}
void sortList() {
 //Node current will point to head
 struct node *current = head, *index = NULL;
 int temp;

 if(head == NULL) {
 return;
 }
 else {
 while(current != NULL) {
 //Node index will point to node next to current
 index = current->next;

 while(index != NULL) {
 //If current node's data is greater than index's node data, swap the data between them

 if(current->data > index->data) {
 temp = current->data;
 current->data = index->data;
 index->data = temp;
 }
 index = index->next;
 }
 current = current->next;
 }
 }
 }
int main()
{
int i=0;
head=NULL;
while(1)
{
printf("\ninsertion at begning of linked list - 1");
printf("\ninsertion at the end of linked list - 2");
printf("\ndeletion from the end of linked list - 3");
printf("\ndeletion of the data that you want - 4");
printf("\nto sort the limked list - 5\n");
printf("\nexit -6\n");

printf("\nenter the choice of operation to perform on linked list: ");
scanf("%d",&i);
switch(i)
{
case 1:
{
int value;
printf("\nenter the value to be inserted: ");
scanf("%d",&value);
insert_at_begning(value);
display();
break;
}
case 2:
{
int value;
printf("\nenter value to be inserted at the end: ");
scanf("%d",&value);
insert_at_end(value);
display();
break;
}
case 3:
{
delete_from_end();
display();
break;
}
case 4:
{
int value;
display();
printf("\nenter the data that you want to delete from the list shown above:");

scanf("%d",&value);
delete_of_data(value);
display();
break;
}
case 5:
{
 sortList();
 display();
 break;
}
case 6:
{
exit(0);
}
}
}
getch();
}

*/
/*
// C++ Program to remove duplicates in an unsorted
//linked list 


// A linked list node 
struct Node
{
	int data;
	struct Node *next;
};

// Utility function to create a new Node
struct Node *newNode(int data)
{
Node *temp = new Node;
temp->data = data;
temp->next = NULL;
return temp;
}

/Function to remove duplicates from a
unsorted linked list 
void removeDuplicates(struct Node *start)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	/* Pick elements one by one 
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		/* Compare the picked element with rest
		of the elements 
		while (ptr2->next != NULL)
		{
			/* If duplicate then delete it 
			if (ptr1->data == ptr2->next->data)
			{
				/* sequence of steps is important here 
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else /* This is tricky 
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

/* Function to print nodes in a given linked list 
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above function 
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10
	struct Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =
									newNode(11);
	start->next->next->next->next->next->next =
									newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);

	return 0;
}

*/
