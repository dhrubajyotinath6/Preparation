/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Approach 1: Breadth First Search
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        
        bool nullNodeFound = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL){
                nullNodeFound = true;
            }else{
                if(nullNodeFound) return false;
                
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};

/*
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* node, int index, int n) {
        if (node == nullptr) {
            return true;
        }
        // If index assigned to current node is greater or equal to the number of nodes
        // in tree, then the given tree is not a complete binary tree.
        if (index >= n) {
            return false;
        }
        // Recursively move to left and right subtrees.
        return dfs(node->left, 2 * index + 1, n) &&
               dfs(node->right, 2 * index + 2, n);
    }

    bool isCompleteTree(TreeNode* root) {
        return dfs(root, 0, countNodes(root));
    }
};

*/