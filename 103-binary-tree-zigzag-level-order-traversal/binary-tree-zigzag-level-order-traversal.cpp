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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> ans;
        queue <TreeNode*> q; // q for BFS traversal.
        if(root) // Only start bfs if tree is not empty.
            q.push(root);
        bool f = false; // flag to filp the order for odd levels (true), even levels (false).
        while(!q.empty())
        {
            int n = q.size();
            vector <int> tmp(n);
            for(int i = 0; i < n; i++)
            {
                int indx = f? n-i-1: i; // if f is true then it is odd level so index needs to be flipped hence do n-i-1 else even level so take i directly.
                TreeNode* node = q.front();
                q.pop();
                tmp[indx] = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(tmp);
            f = !f; // Filp the flag for next level.
        }
        return ans;
    }
};