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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        
        unordered_map<int, int> m;
        for (auto p = head; p != nullptr; p = p->next){
            m[p->val]++;
        }
        
        ListNode *sentinel = new ListNode(), *temp = sentinel;
        
        for (auto cur = head; cur; cur = cur->next) {
            if (m[cur->val]>1){
                continue;
            }
            temp->next = cur;
            temp = temp->next;
        }
        temp->next = NULL;
        return sentinel->next;
            
    }
};