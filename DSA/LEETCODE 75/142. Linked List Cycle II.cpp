//Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

=>

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