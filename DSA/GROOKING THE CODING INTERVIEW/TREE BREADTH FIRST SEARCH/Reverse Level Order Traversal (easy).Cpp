Given a binary tree, populate an array to represent its level - by - level traversal in reverse order,
    i.e., the lowest level comes first.You should populate the values of all nodes in each level from left to right in separate sub - arrays.

                                                                                                                                      class ReverseLevelOrderTraversal
{
public:
    static deque<vector<int>> traverse(TreeNode *root)
    {
        deque<vector<int>> result = deque<vector<int>>();
        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int levelSize = queue.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = queue.front();
                queue.pop();
                // add the node to the current level
                currentLevel.push_back(currentNode->val);
                // insert the children of current node to the queue
                if (currentNode->left != nullptr)
                {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    queue.push(currentNode->right);
                }
            }
            // append the current level at the beginning
            result.push_front(currentLevel);
        }

        return result;
    }
};

/*
1
2 3
4 5 6 7

[
[4 5 6 7]
[2 3]
[1]
]

*/
