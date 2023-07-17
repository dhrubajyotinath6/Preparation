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
class BSTIterator {
    
private: stack<TreeNode *>myStack;
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
         return !myStack.empty();
    }
    
private: 
    void pushAll(TreeNode *node){
        for( ; node != NULL; node = node->left){
            myStack.push(node);
        };
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */