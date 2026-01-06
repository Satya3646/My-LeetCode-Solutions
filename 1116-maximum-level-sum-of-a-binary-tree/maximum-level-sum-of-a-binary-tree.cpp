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
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode*> q; // BFS queue.
        if(root)
            q.push(root);
        int level = 1; // keep track of level.
        int maxSum = INT_MIN;
        int ans = 0;

        while(!q.empty())
        {
            int qs = q.size(); // size of current level.
            int sum = 0;

            while(qs--)
            {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            if(maxSum < sum) // update only if larger sum is there.
            {
                ans = level;
                maxSum = sum;
            }

            level++; // going to next level so increment the level.
        }

        return ans; // return final answer.
    }
};