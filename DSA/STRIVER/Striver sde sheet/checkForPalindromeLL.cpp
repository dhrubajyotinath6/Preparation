
/*
 https://leetcode.com/problems/palindrome-linked-list/discuss/1137696/Short-and-Easy-w-Explanation-or-T-%3A-O(N)-S-%3A-O(1)-Solution-using-Fast-and-Slow
 */
// my leetcode submission --> slow == curr
class Solution {
    public:
        bool isPalindrome(ListNode* head) {

            ListNode * curr = head, * fast = head, * prev = NULL, * next;

            while (fast && fast -> next) {
                fast = fast -> next -> next;

                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }

            curr = (fast ? curr -> next : curr);

            while (curr) {
                if (curr -> val != prev -> val) return false;
                else curr = curr -> next, prev = prev -> next;
            }
            return true;
        }
};

/*
 Explanation | T : O(N), S : O(1) Solution using Fast & Slow

 We can obviously solve this problem the easy way by using a stack. 
 Just iterate over the linked list in one pass, pushing all the values into stack. 
 In the second pass, start again from head, pop each element from stack and compare it against current node's value. 
 If there's a mistmatch, the linked list isn't a palindrome and vice-versa.

    Solution - O(N) : O(1)

We can solve the problem in O(1) space complexity. 
For this, we can reverse the linked list from start till middle of linked list 
and then we can simple match each element in the first half and second half to determine if linked list is palindrome.

The middle of linked list can be found using the slow-fast pointer approach. 
To avoid an extra pass, we can also reverse the first half side by side while we find the middle element. We have two cases -

    *** Linked list is even length - There will be two middle elements(say e1 & e2) and at end of iteration, our slow pointer will end at e1.

    Eg. Consider 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null
s = slow pointer, f = fast pointer, p = previous to slow pointer.

         Simple traversal to find mid               |      Traversal to find mid & reverse element alongside
   f                                                |            f
   s                                                |      p     s
1. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null     |    null    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null
                                                    |
                                                    |
             f                                      |                      f
        s                                           |            p    s
2. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null     |    null <- 1    2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null
                                                    |
                       f                            |                               f
             s                                      |                 p   s
3. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null     |    null <- 1 <- 2   3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null
                                                    |
                                 f                  |                                         f
                  s                                 |                      p   s
4. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null     |    null <- 1 <- 2 <- 3   4 -> 5 -> 6 -> 7 -> 8 -> null
                                                    |
                                            f       |                                                    f
                       s                            |                           p   s
5. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null     |    null <- 1 <- 2 <- 3 <- 4   5 -> 6 -> 7 -> 8 -> null

prev to slow pointer ends at e1, slow pointer ends at e2 and fast pointer ends at null.
We can directly start comparing linked list with heads at p and s and return true if they match & vice-versa


    ***Linked list is odd length - There will be single middle element at which the slow pointer will point to at the end of iteration.

    Eg. Consider 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
s = slow pointer, f = fast pointer, p = previous to slow pointer.

         Simple traversal to find mid               |      Traversal to find mid & reverse element alongside
   f                                                |            f
   s                                                |      p     s
1. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null          |    null    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
                                                    |
                                                    |
             f                                      |                      f
        s                                           |            p    s
2. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null          |    null <- 1    2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
                                                    |
                       f                            |                               f
             s                                      |                 p   s
3. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null          |    null <- 1 <- 2   3 -> 4 -> 5 -> 6 -> 7 -> null
                                                    |
                                 f                  |                                         f
                  s                                 |                      p   s
4. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null          |    null <- 1 <- 2 <- 3   4 -> 5 -> 6 -> 7 -> null

prev to slow pointer ends at mid - 1, slow pointer ends at mid and fast pointer ends at (last-1)th node.
Now, we can assign s = s-> next and compare linked list beginning at p and s.

So, there's only one small difference for even and odd length linked list palindromes. 

In case of odd length which can be known if fast pointer doesn't end at null ends, 
we just iterate slow pointer forward by 1. We then just compare linked lists starting at prev and slow and return true if the lists are equal, else false.
 

slow = (fast ? slow -> next : slow);  ---> for odd and even length

*/


***********************************************************************************************************************
// striver solution
/*
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null)
            return true;
        ListNode slow=head;
        ListNode fast=head;
        while(fast.next!=null&&fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        slow.next=reverseList(slow.next);
        slow=slow.next;
        while(slow!=null){
            if(head.val!=slow.val)
                return false;
            head=head.next;
            slow=slow.next;
        }
        return true;
    }
    ListNode reverseList(ListNode head) {
        ListNode pre=null;
        ListNode next=null;
        while(head!=null){
            next=head.next;
            head.next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
}
*/

