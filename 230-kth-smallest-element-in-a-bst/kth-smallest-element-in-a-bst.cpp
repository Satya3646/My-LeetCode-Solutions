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
    // Inorder traversal of BST gives the nodes in their sorted so we just make use of it, decrementing k for every nnode we visit and when k becomes zero we just return that node.
    int kthSmallest(TreeNode* root, int &k)
    {
        if(!root)
            return -1;
        int l = kthSmallest(root->left, k); // Explore the left subtree.
        if(l != -1) // If value is not -1 return it.
            return l;
        k--; // Decrement k.
        if(k == 0) // If k = 0 return the current node value.
            return root->val;
        return kthSmallest(root->right, k); // Traverse the right subtree.
    }
};