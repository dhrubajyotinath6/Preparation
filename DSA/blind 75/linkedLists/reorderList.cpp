/*
https://leetcode.com/problems/reorder-list/
https://leetcode.com/problems/reorder-list/discuss/1641006/C%2B%2BPython-Simple-Solutions-w-Explanation-or-2-Pointers-O(N)-and-Inplace-O(1)-Space-Approaches

We are given a list which we need to re-order in alternate fashion like L1 -> Ln-1 -> L2 -> Ln-2...

✔️ Solution - I (2-Pointers using Extra Space)

We can solve this question easily if using extra space is allowed. The re-ordering arrangement basically consist of 1st node, then last node, then 2nd node, then 2nd last node and so on till all nodes are covered. Thus, we just put one node from the start, then one from end in an alternating fashion. In this approach -

We first use an auxillary array to store the nodes of linked-list
Once the array is filled, we initialize two variables L and R which denotes the current positions on the two ends from which we need to re-order the list in alternate fashion

    In odd iteration, we assign the next node as arr[L] and move the L pointer ahead
    In even iteration, we assign the next node as arr[R] and move the R pointer backward

This will re-order the list as alternating nodes from start and end as required.

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        for(auto iter = head; iter; iter = iter -> next)
            arr.push_back(iter);
        
		// pointers to start and end of list. Re-order in alternating fashion from both end
        int L = 1, R = size(arr)-1;
        for(int i = 0; i < size(arr); i++, head = head -> next) 
            if(i & 1)                             // odd iteration:
                head -> next = arr[L++];          //        - pick node from L & update L ptr
            else                                  // even iteration
                head -> next = arr[R--];          //        - pick node from R & update R ptr
        
        head -> next = nullptr;
    }
};

    Time Complexity : O(N), where N is the number of nodes in the linked list. 
We traverse linked list once and store it in array. Then we traverse the array once. 
Thus overall time- O(2N) = O(N)

    Space Complexity : O(N), required to store nodes of list into array


                ****************************************************************

✔️ Solution - II (In-place Transformation)

In the above solution, we are simply using two pointers, one to the start and one to the end of array. 
The nodes pointed by these pointers are picked in alternating manner and then these pointers are iterated in opposite directions. 
This continues till they meet in the middle, i.e, all nodes are covered in the process.

But we are using extra space in the form of array. We required array to be able to iterate the R pointer in the backward direction which wouldnt be possible if we directly used linked list.

However, we can optimize the space by modifying our list to make it possible to iterate backwards from R pointer. We can simply reverse the 2nd half of the list which allows us to place R at the end and iterate backwards till the mid. Then the rest process remains similar in logic as above.

       *  First find the mid of linked list. This can be done using slow & fast pointer algorithm

       *  Then we reverse the 2nd half and place the R pointer at the end

       *  Initialize L pointer to head->next

       *  We can now simply re-order by placing nodes from L and R pointers in alternating fashion till they meet.

    class Solution {
public:
	// 876. Middle of the Linked List - returns the mid of list using slow-fast pointer approach
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while(fast && fast -> next)
            slow = slow -> next,
            fast = fast -> next -> next;            // fast moves at 2x speed
        return slow;                                // slow ends up at mid
    }
	// 206. Reverse Linked List - reverses and returns the head of reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head) {
            auto nextNode = head -> next;           // store next node before reversing next ptr of cur
            head -> next = prev;                    // reverse the next ptr to previous node
            prev = head;                            // update previous node as cur
            head = nextNode;                        // move to orignal next node
        }
        return prev;                                // returns head of reversed list
    }
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        auto mid = middleNode(head);
        auto R = reverseList(mid), L = head -> next;
        for(int i = 0; L != R; i++, head = head -> next)     // re-order in alternating fashion 
            if(i & 1) {                                      // odd iteration:                         
                head -> next = L;
                L = L -> next;
            }
            else {                                          // even iteration:
                head -> next = R;
                R = R -> next;
            }
    }
};


    Time Complexity : O(N), we need O(N) to find mid of list, 
another O(N/2) = O(N) to reverse the 2nd half and finally O(N) to re-order the list. 
Thus overall time: O(3N) = O(N)
    Space Complexity : O(1), only constant extra space is used
*/
