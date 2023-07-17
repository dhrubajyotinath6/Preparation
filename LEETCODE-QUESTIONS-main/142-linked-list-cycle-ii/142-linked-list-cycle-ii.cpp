/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head  || !head->next) return NULL;
        
        ListNode *slow = head, *fast = head, *t = head;
        
        //1->2->3->4->5->6-x
        
        while(fast->next != NULL && fast->next->next != NULL){
            
            fast = fast->next->next;
            slow = slow->next;
            
            
            if(fast == slow){
            
               while(slow != t){
                   t = t->next;
                   slow = slow->next;
               }

                return t;
            }
  
          
        }        
        return NULL; 
    }
};