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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val > key) // key exists in left subtree or the root.
            root->left = deleteNode(root->left, key); 
        else if(root->val < key) // key exists in the right subtree of the root.
            root->right = deleteNode(root->right, key);
        else // Current node is the node to be deleted.
        {
            if(!root->left) // if no left subtree then just return the right subtree deleting the root.
            {
                TreeNode* r = root->right;
                delete root;
                return r;
            }
            else if(!root->right) // if no left subtree then just return the right subtree deleting the root.
            {
                TreeNode* l = root->left;
                delete root;
                return l;
            }
            else // find the successor in the right subtree of the root.
            {
                TreeNode* succ = root->right;
                while(succ->left)
                    succ = succ->left;
                root->val = succ->val; // Assign the value of the successor to the root.
                root->right = deleteNode(root->right, succ->val); // Next we need to delete the successor node.
            }
        }
        return root;
    }
};