#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void InsertAtBegining(int x)
{
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

// C++ WAY
void InsertAtNth(int data, int n)
{
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void DeleteAtNth(int n)
{
    struct Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
    }

    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void Print()
{
    struct Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main()
{

    head = NULL;

    // HERE WE ARE CONSIDERING 1ST BASED INDEXING
    InsertAtBegining(1);    // 1
    InsertAtBegining(2);    // 2  1
    InsertAtBegining(3);    // 3  2  1
    InsertAtBegining(4);    // 4  3  2  1      
    Print();                // 4  3  2  1

    InsertAtNth(67, 2);     //4 67 3 2 1
    Print();                //4 67 3 2 1

    DeleteAtNth(4);
    Print();                // 4 67 3 1

return 0;
}

