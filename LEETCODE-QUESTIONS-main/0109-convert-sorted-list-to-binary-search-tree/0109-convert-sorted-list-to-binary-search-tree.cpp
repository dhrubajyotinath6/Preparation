/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/549841/C%2B%2B-DSW    -- A DSW-based solution , which has O(1) memory complexity


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
public:
    ListNode* tmp;
    
public:
    int findSize(ListNode* head){
        ListNode* temp = head;
        int c = 0;
        
        while(temp != NULL){
            temp = temp->next;
            c++;
        }
        return c;
    }
    
public:
    TreeNode* f(int l, int r){
        
        if(l > r){
            return NULL;
        }
        
        int mid = (l + r)/2;
        
        TreeNode* left = f(l, mid - 1);
        
        
        TreeNode* node = new TreeNode(tmp->val);
        node->left = left;
        
        tmp = tmp->next;
        
        node->right = f(mid + 1, r);
        
        return node;
        
        
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = findSize(head);
        tmp = head;
        return f(0, size-1);
    }
};