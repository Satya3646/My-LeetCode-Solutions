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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left) // If a left subtree exists then get the last node we will visit from the left node in preorder traversal and attach the right subtree to that node, since in preorder we need to visit the right subtree after the left subtree. After this attach the left subtree of curr as the right subtree since linked list is connected using right pointers. Hence the rearranged tree will look like root -> left subtree -> right subtree (connected through right pointers). 
            {
                TreeNode* last = curr->left;
                while(last->right)
                    last = last->right;
                last->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
}; 