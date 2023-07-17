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
  int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath) {
    if (currentNode == nullptr) {
      return 0;
    }

    // add the current node to the path
    currentPath.push_back(currentNode->val);
    int pathCount = 0;
    long pathSum = 0;
    // find the sums of all sub-paths in the current path list
    for (vector<int>::reverse_iterator itr = currentPath.rbegin(); 
                                     itr != currentPath.rend(); ++itr) {
      pathSum += *itr;
      // if the sum of any sub-path is equal to 'S' we increment our path count.
      if (pathSum == S) {
        pathCount++;
      }
    }

    // traverse the left sub-tree
    pathCount += countPathsRecursive(currentNode->left, S, currentPath);
    // traverse the right sub-tree
    pathCount += countPathsRecursive(currentNode->right, S, currentPath);

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    currentPath.pop_back();

    return pathCount;
  }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> currentPath;
        return countPathsRecursive(root, targetSum, currentPath); 
    }
};