/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/

class Solution {
public:
	// 876. Middle of the Linked List - returns the mid of list using slow-fast pointer approach
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while(fast && fast -> next)
            slow = slow -> next,
            fast = fast -> next -> next;            // fast moves at 2x speed
        return slow;                                // slow ends up at mid
    }
	// 206. Reverse Linked List - reverses and returns the head of reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head) {
            auto nextNode = head -> next;           // store next node before reversing next ptr of cur
            head -> next = prev;                    // reverse the next ptr to previous node
            prev = head;                            // update previous node as cur
            head = nextNode;                        // move to orignal next node
        }
        return prev;                                // returns head of reversed list
    }
    void reorderList(ListNode* head) {
        
        if(!head || !head -> next) return;
        
        auto mid = middleNode(head);
        
        auto R = reverseList(mid), L = head -> next;
        
        for(int i = 0; L != R; i++) { // re-order in alternating fashion 
            
             // when i = 1,3,5,7...
            if(i & 1) {                              
                head -> next = L;
                L = L -> next;
            }
            // when i = 0,2,6,8...
            else {
                head -> next = R;
                R = R -> next;
            }
            
             head = head -> next;
        }    
            
           
    }
};