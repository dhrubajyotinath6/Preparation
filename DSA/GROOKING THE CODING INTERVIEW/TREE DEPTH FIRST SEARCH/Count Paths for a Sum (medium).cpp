/*
Given a binary tree and a number ‘S’,
find all paths in the tree such that the sum of all the node values of each path equals ‘S’.
Please note that the paths can start or end at any node
but all paths must follow direction from parent to child(top to bottom).

*/

class CountAllPathSum
{
public:
    static int countPaths(TreeNode *root, int S)
    {
        vector<int> currentPath;
        return countPathsRecursive(root, S, currentPath);
    }

private:
    static int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath)
    {
        if (currentNode == nullptr)
        {
            return 0;
        }

        // add the current node to the path
        currentPath.push_back(currentNode->val);
        int pathCount = 0, pathSum = 0;
        // find the sums of all sub-paths in the current path list
        for (vector<int>::reverse_iterator itr = currentPath.rbegin();
             itr != currentPath.rend(); ++itr)
        {
            pathSum += *itr;
            // if the sum of any sub-path is equal to 'S' we increment our path count.
            if (pathSum == S)
            {
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
};
