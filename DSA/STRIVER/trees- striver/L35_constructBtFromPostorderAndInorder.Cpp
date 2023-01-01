/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

*/

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return NULL;

        map<int, int> hm;

        for (int i = 0; i < inorder.size(); ++i)
            hm[inorder[i]] = i;

        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, hm);
    }

    TreeNode *buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe,
                              map<int, int> &hm)
    {
        if (ps > pe || is > ie)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pe]);

        int ri = hm[postorder[pe]];

                                                                           //     ps + length - 1
        TreeNode *leftchild = buildTreePostIn(inorder, is, ri - 1, postorder, ps, ps + ri - is - 1, hm);
        TreeNode *rightchild = buildTreePostIn(inorder, ri + 1, ie, postorder, ps + ri - is, pe - 1, hm);

        root->left = leftchild;
        root->right = rightchild;

        return root;
    }
};
