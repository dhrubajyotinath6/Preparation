
/*
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
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
 https://leetcode.com/problems/odd-even-linked-list/discuss/1607746/C%2B%2B-Simple-Solution-w-Images-and-Explanation-or-Brute-Force-%2B-O(1)-In-place-Transformation
 https://leetcode.com/problems/odd-even-linked-list/solution/
 */
 
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head)
            return NULL;

        auto odd = head, even = head->next, evenHead = even;

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }
};

