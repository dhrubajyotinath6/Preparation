#include<bits/stdc++.h>
 
using namespace std;

struct Node{
    int data;
    struct Node* link;
};
struct Node* top = NULL;

void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop(){
    struct Node* temp;

    if(top == NULL){
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}

void Print()
{
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n\n");
}

int main(){

    Push(2);
    Print();

    Push(5);
    Print();

    Push(28);
    Print();
    
    Pop();
    Print();

    Push(132);
    Print();



    return 0;
}