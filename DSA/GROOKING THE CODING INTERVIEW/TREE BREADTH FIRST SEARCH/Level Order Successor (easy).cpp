/*
Given a binary tree and a node, find the level order successor of the given node in the tree.
The level order successor is the node that appears right after the given node in the level order traversal.

*/

class LevelOrderSuccessor
{
public:
    static TreeNode *findSuccessor(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TreeNode *currentNode = queue.front();
            queue.pop();

            // insert the children of current node in the queue
            if (currentNode->left != nullptr)
            {
                queue.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                queue.push(currentNode->right);
            }

            // break if we have found the key
            if (currentNode->val == key)
            {
                break;
            }
        }

        return queue.front();
    }
};