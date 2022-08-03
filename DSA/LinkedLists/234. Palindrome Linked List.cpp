/*
Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


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
 *
 * https://leetcode.com/problems/palindrome-linked-list/discuss/1137696/Short-and-Easy-w-Explanation-or-T-%3A-O(N)-S-%3A-O(1)-Solution-using-Fast-and-Slow
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        ListNode *curr = head, *fast = head, *prev = NULL, *next;

        while (fast && fast->next)
        {
            fast = fast->next->next;

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr = (fast ? curr->next : curr);

        while (curr)
        {
            if (curr->val != prev->val)
                return false;
            else
                curr = curr->next, prev = prev->next;
        }
        return true;
    }
};