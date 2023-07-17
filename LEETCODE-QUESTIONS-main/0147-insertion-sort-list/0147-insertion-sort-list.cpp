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
//https://leetcode.com/problems/insertion-sort-list/discuss/46420/An-easy-and-clear-way-to-sort-(-O(1)-space-)
/*
public ListNode insertionSortList(ListNode head) {

		if( head == null ){
			return head;
		}
		
		ListNode helper = new ListNode(0); //new starter of the sorted list
		ListNode cur = head; //the node will be inserted
		ListNode pre = helper; //insert node between pre and pre.next
		ListNode next = null; //the next node will be inserted
		//not the end of input list
		
        while( cur != null ){
			next = cur.next;
			//find the right place to insert
			while( pre.next != null && pre.next.val < cur.val ){
				pre = pre.next;
			}
			//insert between pre and pre.next
			cur.next = pre.next;
			pre.next = cur;
			pre = helper;
			cur = next;
		}
		
		return helper.next;
	}


*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
    if(!head || !head->next) return head;
        
     ListNode* dummy = new ListNode(0);
     ListNode* prev = dummy;

    while (head != NULL) {
        ListNode* temp = head->next;
        
        /* Before insert, the prev is at the last node of the sorted list.
           Only the last node's value is larger than the current inserting node 
           should we move the temp back to the head*/
        if (prev->val >= head->val) prev = dummy;

        while (prev->next != NULL && prev->next->val < head->val) {
            prev = prev->next;
        }
        
        head->next = prev->next;
        prev->next = head;
        // prev = dummy; // Don't set prev to the head of the list after insert
        head = temp;
    }
    return dummy->next;
    }
};