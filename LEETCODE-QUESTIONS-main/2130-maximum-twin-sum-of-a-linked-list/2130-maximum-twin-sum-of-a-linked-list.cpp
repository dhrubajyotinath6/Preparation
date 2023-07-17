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
    int pairSum(ListNode* head) {
        
         ListNode * curr = head, * fast = head, * prev = NULL, * next;

            while (fast && fast -> next) {
                fast = fast -> next -> next;

                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
        
            int maxi = 0;

            while (curr) {
                
               int sum = 0;
                
               sum += curr->val;
               curr = curr->next;
               sum += prev->val;
               prev = prev->next;
                
               maxi = max(maxi, sum);
                
            }
       return maxi;     
    }
};