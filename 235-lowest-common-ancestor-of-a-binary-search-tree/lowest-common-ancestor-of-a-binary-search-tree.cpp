/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        int curr = root->val,
            P = p->val,
            Q = q->val;
        if(P < curr && Q < curr) // Search the left subtree only since both are less than root.
            return lowestCommonAncestor(root->left, p, q);
        if(P > curr && Q > curr) // Search the right subtree only since both are greater then root.
            return lowestCommonAncestor(root->right, p, q);
        return root; // In other cases current node will be the LCA of given nodes.
    }
};