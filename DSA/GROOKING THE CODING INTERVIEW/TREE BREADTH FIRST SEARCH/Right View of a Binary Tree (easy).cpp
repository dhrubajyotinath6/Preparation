/*
Given a binary tree, return an array containing nodes in its right view.
The right view of a binary tree is the set of nodes visible when the tree is seen from the right side
*/

class RightViewTree
{
public:
    static vector<TreeNode *> traverse(TreeNode *root)
    {
        vector<TreeNode *> result;
        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = queue.front();
                queue.pop();
                // if it is the last node of this level, add it to the result
                if (i == levelSize - 1)
                {
                    result.push_back(currentNode);
                }
                // insert the children of current node in the queue
                if (currentNode->left != nullptr)
                {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    queue.push(currentNode->right);
                }
            }
        }

        return result;
    }
};
