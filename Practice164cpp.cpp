// 165. Min and Max of Binary Tree: For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
// Return the output as an object of Pair class, which is already created.

/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

/*
    The first value of the pair must be the minimum value in the tree and
    the second value of the pair must be the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    if (root->right == NULL && root->left == NULL)
    {
        pair<int, int> p;
        p.first = root->data;
        p.second = root->data;
        return p;
    }

    pair<int, int> ans;
    ans.first = root->data;
    ans.second = root->data;

    if (root->left != NULL)
    {
        pair<int, int> leftAns = getMinAndMax(root->left);
        ans.first = min(ans.first, leftAns.first);
        ans.second = max(ans.second, leftAns.second);
    }

    if (root->right != NULL)
    {
        pair<int, int> rightAns = getMinAndMax(root->right);
        ans.first = min(ans.first, rightAns.first);
        ans.second = max(ans.second, rightAns.second);
    }

    return ans;
}