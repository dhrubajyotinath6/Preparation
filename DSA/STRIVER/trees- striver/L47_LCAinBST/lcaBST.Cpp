class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int curr = root->val; 
        if(curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};


//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/discuss/937341/C%2B%2B-in-7-Lines-with-100-Fast-Space-and-Time
*/

// It is just a variation of Intersection of LinkedList!

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        Node* a = p;
        Node* b = q;
        
        while(a != b){
            a = (a == NULL) ? q : a->parent;
            b = (b == NULL) ? p : b->parent;
        }
        
        return a;
    }
};
