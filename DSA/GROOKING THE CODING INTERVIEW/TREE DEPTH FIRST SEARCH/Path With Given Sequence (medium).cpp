/*
Given a binary tree and a number sequence,
find if the sequence is present as a root-to-leaf path in the given tree.

*/

class PathWithGivenSequence
{
public:
    static bool findPath(TreeNode *root, const vector<int> &sequence)
    {
        if (root == nullptr)
        {
            return sequence.empty();
        }

        return findPathRecursive(root, sequence, 0);
    }

private:
    static bool findPathRecursive(TreeNode *currentNode, const vector<int> &sequence,
                                  int sequenceIndex)
    {
        if (currentNode == nullptr)
        {
            return false;
        }

        if (sequenceIndex >= sequence.size() || currentNode->val != sequence[sequenceIndex])
        {
            return false;
        }

        // if the current node is a leaf, add it is the end of the sequence, we have found
        // a path!
        if (currentNode->left == nullptr && currentNode->right == nullptr &&
            sequenceIndex == sequence.size() - 1)
        {
            return true;
        }

        // recursively call to traverse the left and right sub-tree
        // return true if any of the two recursive call return true
        return findPathRecursive(currentNode->left, sequence, sequenceIndex + 1) ||
               findPathRecursive(currentNode->right, sequence, sequenceIndex + 1);
    }
};
