//https://leetcode.com/problems/binary-tree-inorder-traversal/

//3 SOLUTIONS ( DFS + ITERATIVE + MORRIS TRANSVERSAL [TC -> O(n), SC -> O(1)] )

/*
DFS (Recursive)
TC : O(n)
SC: O(n)
The worst case space required is O(n), and in the average case it's O(log n) where n is number of nodes.
*/

class Solution {
    
    void dfs(TreeNode* node, vector<int> &ans){
        
        if(node->left) dfs(node->left,ans);
        
        ans.push_back(node->val);
            
        if(node->right) dfs(node->right,ans);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        dfs(root,ans);
        
        return ans;
    }
};

/*
ITERATIVE (USING STACK)

TC -> O(N)
SC -> O(N)
*/

class Solution {    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
         stack<TreeNode*> st;
         vector<int> ans;

         TreeNode* node = root;

         if(node == NULL) return ans;

        while(true){
            
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                
                if(st.empty() == true) break;
                
                node = st.top();
                st.pop();
                
                ans.push_back(node->val);
                
                node = node->right;
            }
        }
        
        return ans;
        
    }
};

/*  
MORRIS TRANSVERSAL
TC -> O(N)
SC -> O(1)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder; 
        
        TreeNode* cur = root;
        
        if(cur == NULL) return inorder;
        
        while(cur != NULL) {
            
            if(cur->left == NULL) {
                inorder.push_back(cur->val); 
                cur = cur->right; 
            }
            
            else {
                TreeNode* prev = cur->left; 
                
                while(prev->right != NULL && prev->right != cur) {
                    prev = prev->right; 
                }
                
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left; 
                }
                else {
                    prev->right = NULL; 
                    inorder.push_back(cur->val); 
                    cur = cur->right; 
                }
            }
        }
        return inorder; 
    }
}; 