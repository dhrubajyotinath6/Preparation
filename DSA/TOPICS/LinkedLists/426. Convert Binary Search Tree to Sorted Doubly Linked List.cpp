/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list.
For a circular doubly linked list, the predecessor of the first element is the last element,
and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation,
the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor.
You should return the pointer to the smallest element of the linked list.



Example 1:



Input: root = [4,2,5,1,3]


Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST.
The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Example 2:

Input: root = [2,1,3]
Output: [1,2,3]

*/

/*
https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/solution/

https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/discuss/273834/Morris-traversal-idea-to-beat-100-time-and-space

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution
{
public:
    Node *first = NULL;
    Node *last = NULL;

    void helper(Node *node)
    {

        if (node)
        {

            helper(node->left);

            if (last)
            {
                // link the previous node (last)
                // with the current one (node)
                last->right = node;
                node->left = last;
            }
            else
            {
                // keep the smallest node
                // to close DLL later on
                first = node;
            }
            last = node;

            helper(node->right);
        }
    }

    Node *treeToDoublyList(Node *root)
    {

        if (root == NULL)
            return NULL;

        helper(root);

        // close DLL
        last->right = first;
        first->left = last;

        return first;
    }
};