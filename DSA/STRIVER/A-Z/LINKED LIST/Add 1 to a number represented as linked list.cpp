/*
https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

A number N is represented in Linked List such that each digit corresponds to a node in linked list. 
You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124
*/

class Solution{
    
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













































































































































































































































