/*
  ******************  STUDY MERGE SORT  ******************

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]


Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
*/


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

//https://leetcode.com/problems/sort-list/solution/

//CHECK APPROCH 1 -> SC : O(1)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if (!head || !head->next)
            return head;
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
    }

    
    ListNode* getMid(ListNode* head){
        
        auto fast = head, slow = head;
        
        fast = fast->next->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = NULL;
        
    return temp;
  }
};