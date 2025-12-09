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
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair <TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            unsigned long long l = 0, r = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front().first;
                unsigned long long x = q.front().second;
                if(i == 0)
                    l = x;
                if(i == n-1)
                    r = x;
                q.pop();
                if(node->left)
                    q.push({node->left, (x<<1)});
                if(node->right)
                    q.push({node->right, (x<<1)+1});
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};