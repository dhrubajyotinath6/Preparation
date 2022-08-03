class ConnectLevelOrderSiblings
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
        while (!queue.empty())
        {
            TreeNode *previousNode = nullptr;
            int levelSize = queue.size();
            // connect all nodes of this level
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = queue.front();
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
    }
};
