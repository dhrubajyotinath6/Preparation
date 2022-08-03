/*
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.

*/

class ReverseEveryKElements
{
public:
    static ListNode *reverse(ListNode *head, int k)
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
                lastNodeOfPreviousPart->next =
                    previous; // 'previous' is now the first node of the sub-list
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
};