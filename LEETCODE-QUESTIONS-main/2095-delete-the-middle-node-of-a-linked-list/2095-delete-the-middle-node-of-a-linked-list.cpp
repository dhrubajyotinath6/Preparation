/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // 0 or only 1 nodes
        if(!head || !head->next) return nullptr;
        
        ListNode *slow = head, *fast = head->next->next;
        
        
        //actually we have to reach the node before the middle of the 
        //linked list so i have intialize the fast pointer one step ahead as show above
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};