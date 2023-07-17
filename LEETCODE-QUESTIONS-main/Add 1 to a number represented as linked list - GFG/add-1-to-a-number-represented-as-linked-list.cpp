//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
Node *reverse(Node *head){ 
    
    Node * prev = NULL; 
    Node * current = head; 
    Node * next; 
    
    while (current != NULL){ 
        
        next = current->next; 
        current->next = prev;
        
        prev = current; 
        current = next; 
    } 
    
    return prev;
    
}

Node *add(Node *head){ 
    
    // res is head node of the resultant list 
    Node* res = head; 
    Node *temp; 
  
    int carry = 1, sum; 
  
    while (head != NULL ){
        
        sum = carry + head->data; 
  
        // update carry for next calculation 
        carry = (sum >= 10)? 1 : 0; 
  
        // update sum if it is greater than 10 , 12%10 = 2
        sum = sum % 10; 
  
        // Create a new node with sum as data 
        head->data = sum; 
  
        // Move head and second pointers to next nodes 
        temp = head; 
        head = head->next; 
    } 
  
    // if some carry is still there, add a new node to 
    // result list. 
    if (carry > 0) 
        temp->next = new Node(carry); 
  
    // return head of the resultant list 
    return res; 
} 


public:
  Node* addOne(Node *head){
        head = reverse(head);
        
        head = add(head);
        
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends