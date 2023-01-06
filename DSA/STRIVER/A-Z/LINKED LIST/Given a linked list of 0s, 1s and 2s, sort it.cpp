/*
https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.


Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
*/

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
    // Add code here
    if (!head || !(head->next))
    return head;
  
    // Create three dummy nodes to point to beginning of
    // three linked lists. These dummy nodes are created to
    // avoid many null checks.
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);
  
    // Initialize current pointers for three
    // lists and whole list.
    Node *zero = zeroD, *one = oneD, *two = twoD;
  
    // Traverse list
    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        }
        else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
  
    // Attach three lists
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;
  
    // Updated head
    head = zeroD->next;
  
    // Delete dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;
  
    return head;
    }
};
