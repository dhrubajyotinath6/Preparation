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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0) return head;
        
        int len = 1;
        
        ListNode* curr = head;
        
        while(curr->next){
            len++;
            curr = curr->next;
        }
        
        k = k%len;
        
        if(k == 0) return head;
        
        k = len - k;
        
        curr->next = head;
        
        while(k>0){
            curr = curr->next;
            k--;
        }
        
        head = curr->next;
        curr->next = NULL;
        
        return head;
        
    }
};