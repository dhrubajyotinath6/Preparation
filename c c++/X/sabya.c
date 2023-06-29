#include<stdio.h> // Write a program to create a doubly linked linked list
#include<stdlib.h> // and perform insertions and deletions in all cases.
#include<conio.h>
#include<string.h>
struct node
{
struct node *prev;
struct node *next;
char hotel[30];
int rating;
char address[30];
char room_type[30];
int room_availability;
float price_per_room;
int gst;
};
struct node *head ,*current;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main ()
{
int choice =0;
while(choice != 7)
{
printf("\n\n\n");
printf("1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4. Delete from last\n5.Show\n6.Exit");

printf("\nEnter your choice?\n");
scanf("\n%d",&choice);
switch(choice)
{
case 1:
insertion_beginning();
break;
case 2:
insertion_last();
break;
case 3:
deletion_beginning();
break;
case 4:
deletion_last();
break;
case 5:
display();
break;
case 6:
exit(0);
break;
default:
printf("Please enter valid choice..");
}
}
}
void insertion_beginning()
{
struct node *ptr;
int r;
char h[30];
char add[30];
char rt[30];
int ra;
float p;
ptr = (struct node *)malloc(sizeof(struct node));
if(ptr == NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("\n\nEnter Hotel Name: ");
scanf("%s",h);
printf("\nEnter rating: ");
scanf("%d",&r);
printf("\nEnter Address: ");
scanf("%s", add);
printf("\nEnter room type: ");
scanf("%s", rt);
printf("\nEnter room availability: ");
scanf("%d", &ra);
printf("\nEnter price per room: ");
scanf("%f",&p);




if(head==NULL)
{
ptr->next = NULL;
ptr->prev=NULL;
ptr->rating=r;
strcpy(ptr->hotel,h);
strcpy(ptr->address,add);
strcpy(ptr->room_type,rt);
ptr->room_availability= ra;
ptr->price_per_room=p;

head=ptr;
}
else
{
ptr->rating=r;
strcpy(ptr->hotel,h);
strcpy(ptr->address,add);
strcpy(ptr->room_type,rt);
ptr->room_availability= ra;
ptr->price_per_room=p;
ptr->prev=NULL;
ptr->next = head;
head->prev= ptr;
head = ptr;
}
printf("\nNode inserted\n");
}
}
void insertion_last()
{
struct node *ptr,*temp;
int r;
char h[30];
char add[30];
char rt[30];
int ra;
float p;
ptr = (struct node *) malloc(sizeof(struct node));
if(ptr == NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("\n\nEnter Hotel Name: ");
scanf("%s",h);
printf("\nEnter rating: ");
scanf("%d",&r);
printf("\nEnter Address: ");
scanf("%s", add);
printf("\nEnter room type: ");
scanf("%s", rt);
printf("\nEnter room availability: ");
scanf("%d", &ra);
printf("\nEnter price per room: ");
scanf("%f",&p);

ptr->rating=r;
strcpy(ptr->hotel,h);
strcpy(ptr->address,add);
strcpy(ptr->room_type,rt);
ptr->room_availability= ra;
ptr->price_per_room=p;

if(head == NULL)
{
ptr->next = NULL;
ptr->prev = NULL;
head = ptr;
}
else
{
temp = head;
while(temp->next!=NULL)
{
temp = temp->next;
}
temp->next = ptr;
ptr ->prev=temp;
ptr->next = NULL;
}
}
printf("\nnode inserted\n");
}
void deletion_beginning()
{
struct node *ptr;
if(head == NULL)
{
printf("\n UNDERFLOW");
}
else if(head->next == NULL)
{
head = NULL;
free(head);
printf("\nnode deleted \n");
}
else
{
ptr = head;
head = head -> next;
head -> prev = NULL;
free(ptr);
printf("\nnode deleted \n");
}
}
void deletion_last()
{
struct node *ptr;
if(head == NULL)
{
printf("\n UNDERFLOW");
}
else if(head->next == NULL)
{
head = NULL;
free(head);
printf("\nnode deleted \n");
}
else
{
ptr = head;
if(ptr->next != NULL)
{
ptr = ptr -> next;
}
ptr -> prev -> next = NULL;
free(ptr);
printf("\nnode deleted \n");
}
}

void insertionSort() { 
    struct node *current = NULL, *index = NULL; 
    char temp[30];  
    if(head == NULL) { 
        return; 
    } 
    else { 
        for(current = head; current->next != NULL; current = current->next) { 
 
            for(index = current->next; index != NULL; index = index->next) { 
   
                if(current->hotel > index->hotel) { 
                    strcpy(temp, current->hotel); 
                    strcpy(current->hotel,index->hotel); 
                    strcpy(index->hotel,temp); 
                   
                     } 
            } 
        } 
    } 
}



void display()
{
struct node *ptr;
printf("\n printing values : \n");
ptr = head;
int duplicate;
while(ptr != NULL)
{
    
printf("Hotel Name: %s\n",ptr->hotel);
printf("Rating: %d\n",ptr->rating);
printf("Address: %s\n",ptr->address);
printf("Room type:  %s\n",ptr->room_type);
printf("Room Availability: %d\n",ptr->room_availability);
printf("Price per room: %f\n\n\n\n",ptr->price_per_room);

ptr=ptr->next;
}
}