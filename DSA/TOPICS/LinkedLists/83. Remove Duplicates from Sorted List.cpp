/*
Input: head = [1,1,2,3,3]
Output: [1,2,3]

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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        ListNode *current = head;

        // ListNode *next_next;

        if (!current)
            return current;

        while (current->next != NULL)
        {

            if (current->val == current->next->val)
            {
                // next_next = current->next->next;
                // free(current->next);
                // current->next = next_next;
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};