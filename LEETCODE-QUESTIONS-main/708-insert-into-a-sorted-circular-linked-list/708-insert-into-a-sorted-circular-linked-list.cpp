/*https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/solution/      --> very very imp

https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/discuss/136918/(Accepted)-C%2B%2B-Solution-in-O(n)-with-Explanation

Case 1). The value of new node sits between the minimal and maximal values of the current list. As a result, it should be inserted within the list.

Case 2). The value of new node goes beyond the minimal and maximal values of the current list, either less than the minimal value or greater than the maximal value. In either case, the new node should be added right after the tail node (i.e. the node with the maximal value of the list).
    The Case 2.1 corresponds to the condition where the value to be inserted is greater than or equal to the one of tail node, i.e. {insertVal >= prev.val}.
    The Case 2.2 corresponds to the condition where the value to be inserted is less than or equal to the head node, i.e. {insertVal <= curr.val}.
    
Case 3). Finally, there is one case that does not fall into any of the above two cases. This is the case where the list contains uniform values.

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        if(head == NULL){
            Node* newNode = new Node(insertVal, nullptr);
            newNode->next = newNode;
            return newNode;
        }
        
        Node* prev = head;
        Node* next = head->next;
        bool toInsert = false;
        
        while (true) {
        // insert when:
        // 1. prev <= insertVal <= next
        // 2. insertVal < min (insert at the tail)
        // 3. insertVal > max (insert at the tail)
        if ((prev->val <= insertVal && insertVal <= next->val) ||
            (prev->val > next->val && insertVal < next->val) ||
            (prev->val > next->val && insertVal > prev->val)) {
            prev->next = new Node(insertVal, next);
            toInsert = true;
            break;
        }

        prev = prev->next;
        next = next->next;
        if (prev == head) break;
    }
    
    if (!toInsert) {
        // The only reason why `value` was not inserted is that
        // all values in the list are the same and are not equal to `value`.
        // So, we could insert `value` anywhere.
        prev->next = new Node(insertVal, next);
    }

    return head;
        
        
        
    }
};