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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p & !q) // if both are null they are identical.
            return true;
        if((p && !q) || (!p && q)) // if only one of them is null the not identical.
            return false;
        if(p->val != q->val) // Check their values.
            return false;
        // Next check if the left and right subtrees are identical or not.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};