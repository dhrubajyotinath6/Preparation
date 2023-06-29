#include<stdio.h>   
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


void insert_at_middle(int value, int loc)
{
 struct node *var2,*temp;

 var=(struct node *)malloc(sizeof (struct node));
 var->data=value;

 temp=head;

 if(head==NULL)
 {
 head=var;
 head->next=NULL;
 }
 else
 {
 while(temp->data!=loc)
 {
 temp=temp->next;
 }
 var->next = temp->next;
 temp->next = var;
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

void delete_neg()
{ 
 struct node *temp;
 struct node *temp1;
 trav=head;
 
 temp = trav->next;
 temp1 = temp->next;
 if(trav==NULL)
 {
 printf("\nList is Empty\n");
 }
 else
 {
 while(temp1->next!=NULL)
 {
 if(trav->data < 0 && trav->next->data>=0)
 {
     delete_of_data(temp->data);
     temp = temp1;
     temp1=temp1->next;
 }
 temp = temp->next;
 trav=trav->next;
 temp1 = temp1->next;

 }
 printf("\n\n");
 }
}


int main()
{
 insert_at_begning(5);
 insert_at_end(6);
 insert_at_begning(-8);
 insert_at_begning(1);
 insert_at_begning(-9);
 display();
 delete_neg();
 
 display();
 return 0;
}
 