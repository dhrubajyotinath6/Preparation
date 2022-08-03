/*
Given a binary tree, populate an array to represent the averages of all of its levels.
*/

class LevelAverage
{
public:
    static vector<double> findLevelAverages(TreeNode *root)
    {
        vector<double> result;

        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int levelSize = queue.size();
            double levelSum = 0;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = queue.front();
                queue.pop();
                // add the node's value to the running sum
                levelSum += currentNode->val;
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
            // append the current level's average to the result array
            result.push_back(levelSum / levelSize);
        }

        return result;
    }
};