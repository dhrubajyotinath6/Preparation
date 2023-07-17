//https://leetcode.com/problems/remove-linked-list-elements/solution/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
The things are more complicated when the node or nodes to delete are 
in the head of linked list.

Sentinel nodes are widely used in trees and linked lists as pseudo-
heads, pseudo-tails, markers of level end, etc. They are purely 
functional, and usually does not hold any data. Their main purpose is 
to standardize the situation, for example, make linked list to be 
never empty and never headless and hence simplify insert and delete.
 */


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
       ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        
        ListNode *prev = sentinel, *curr = head , *toDelete = nullptr;
        
        while(curr != nullptr){
            
            if(curr->val == val){
                prev->next = curr->next;
                toDelete = curr;
            }else{
               prev = curr;
            }
            curr = curr->next;
            
            if(toDelete != nullptr){
                delete toDelete;
                toDelete =nullptr;
            }
        }    
        
        
       ListNode *ret = sentinel->next;
       delete sentinel;
       return ret;
    }
};