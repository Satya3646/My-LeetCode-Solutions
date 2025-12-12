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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root)
            return node;
        TreeNode* curr = root;
        while(curr != node) // When we attach the node to the tree iteration should end.
        {
            if(curr->val > val) // if current is greater the node belongs to its left.
            {
                if(!curr->left) // if a right doesnt exist then attach the node as right.
                    curr->left = node;
                curr = curr->left;
            }
            else // if current is smaller the node belongs to its right.
            {
                if(!curr->right) // if a left doesnt exist then attach the node as left.
                    curr->right = node;
                curr = curr->right;
            }
        }
        return root;
    }
};