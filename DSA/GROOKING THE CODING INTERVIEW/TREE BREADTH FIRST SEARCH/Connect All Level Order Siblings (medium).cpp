/*
Given a binary tree, connect each node with its level order successor.
The last node of each level should point to the first node of the next level.

*/

class ConnectAllSiblings
{
public:
    static void connect(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        TreeNode *currentNode = nullptr, *previousNode = nullptr;
        while (!queue.empty())
        {
            currentNode = queue.front();
            queue.pop();
            if (previousNode != nullptr)
            {
                previousNode->next = currentNode;
            }
            previousNode = currentNode;

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
};