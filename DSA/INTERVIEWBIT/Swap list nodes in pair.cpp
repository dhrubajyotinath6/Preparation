/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,

Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *head, int k)
{

    if (k <= 1 || head == nullptr)
    {
        return head;
    }

    ListNode *current = head, *previous = nullptr;

    while (true)
    {

        ListNode *lastNodeOfPreviousPart = previous;
        // after reversing the LList 'current' will become the last node of the sub-list
        ListNode *lastNodeOfSubList = current;
        ListNode *next = nullptr; // will be used to temporarily store the next node
        // reverse 'k' nodes
        for (int i = 0; current != nullptr && i < k; i++)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        // connect with the previous part
        if (lastNodeOfPreviousPart != nullptr)
        {
            lastNodeOfPreviousPart->next = previous; // 'previous' is now the first node of the sub-list
        }
        else
        { // this means we are changing the first node (head) of the LinkedList
            head = previous;
        }

        // connect with the next part
        lastNodeOfSubList->next = current;

        if (current == nullptr)
        { // break, if we've reached the end of the LinkedList
            break;
        }
        // prepare for the next sub-list
        previous = lastNodeOfSubList;
    }

    return head;
}

ListNode *Solution::swapPairs(ListNode *A)
{

    ListNode *ans = reverse(A, 2);

    return ans;
}
