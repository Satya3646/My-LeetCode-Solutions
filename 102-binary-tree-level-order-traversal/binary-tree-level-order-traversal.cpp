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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        vector <vector <int>> ans;
        if(!root) // If tree is empty return empty answer
            return ans;
        q.push(root); // Put the root into the queue to start traversal
        while(!q.empty())
        {
            vector <int> tmp; // Vector to store node values in current level
            int n = q.size(); // Number of nodes in current level
            for(int i = 0; i < n; i++)
            {
                // Pop the front node from the queue
                TreeNode *node = q.front(); 
                q.pop();
                tmp.push_back(node->val);
                // Put node of next level into the queue
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(tmp); // Add the current level values to answer
        }
        return ans;
    }
};