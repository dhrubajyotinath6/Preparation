//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/solution/

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
class Solution {
    
    TreeNode* f(vector<int>& nums, int left, int right){
        
        if (left > right){
            return NULL;
        }
        
        int mid = left + (right - left) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = f(nums,left,mid-1);
        root->right = f(nums, mid + 1, right);

        
        return root;
    }
                
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        TreeNode* root  = f(nums, 0, nums.size()-1);
        
        return root;
    }
};