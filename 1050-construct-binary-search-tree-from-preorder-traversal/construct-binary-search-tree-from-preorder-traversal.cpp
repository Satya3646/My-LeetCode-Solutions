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
    int indx = 0;
    TreeNode* bstFromPreorder(vector <int> &preorder, int bound = INT_MAX)
    {
        if(indx == preorder.size() || preorder[indx] > bound) // index out of bounds or value is greater the the bounds the return.
            return nullptr;
        TreeNode* root = new TreeNode(preorder[indx++]); // Create the root.
        root->left = bstFromPreorder(preorder, root->val); // Left subtree range is all values less than root.
        root->right = bstFromPreorder(preorder, bound); // Right subtree range is all values greate than root.
        return root;
    }
};