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
    TreeNode* helper(vector <int> &preorder, int pL, int pR, vector <int> &inorder, int iL, int iR, unordered_map <int, int> &rootLookup)
    {
        if(pL > pR || iL > iR)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pL]);
        int k = rootLookup[preorder[pL]];
        // iL to k-1 will be left subtree inorder.
        // k+1 to iR will be right subtree inorder.
        int leftSize = k-iL;
        // pL+1 to pL+leftSize is left subtree preorder.
        // pL+leftSize+1 to pR is right subtree preorder.
        root->left = helper(preorder, pL+1, pL+leftSize, inorder, iL, k-1, rootLookup);
        root->right = helper(preorder, pL+leftSize+1, pR, inorder, k+1, iR, rootLookup);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map <int, int> rootLookup; // Map to instantly lookup root index.
        for(int i = 0; i < n; i++)
            rootLookup[inorder[i]] = i;
        TreeNode* root = helper(preorder, 0, n-1, inorder, 0, n-1, rootLookup);
        return root;
    }
};