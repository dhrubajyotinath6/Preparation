/*
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6


Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode *res = list1;

        while (list1 != NULL && list2 != NULL)
        {
            ListNode *tmp = NULL;
            while (list1 != NULL && list1->val <= list2->val)
            {
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            swap(list1, list2);
        }
        return res;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.empty())
            return NULL;

        while (lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists.front();
    }
};