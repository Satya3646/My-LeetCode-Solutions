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
    TreeNode* solve(vector <int> &preorder, int low, int high)
    {
        if(low > high) // Breaking condition.
            return nullptr;
        TreeNode* root = new TreeNode(preorder[low]); // Create the root.
        int i = low+1; // Collect the left subtree (all values less than root). 
        while(i <= high && preorder[i] < preorder[low])
            i++;
        // now low is the root, low+1 to i-1 will be values less than the root (left subtree), and i to high will be the values greater than the root (right subtree).
        root->left = solve(preorder, low+1, i-1);
        root->right = solve(preorder, i, high);
        return root;
    }

    TreeNode* bstFromPreorder(vector <int> &preorder)
    {
        int n = preorder.size();
        return solve(preorder, 0, n-1);
    }
};