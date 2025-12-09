/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map <TreeNode*, TreeNode*> &parent)
    {
        if(!root)
            return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if(l)
            parent[l] = root;
        if(r)
            parent[r] = root;
        dfs(l, parent);
        dfs(r, parent);
    }

    vector <int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> parent; // Node to parent mapping.
        dfs(root, parent); // Update the map.
        queue <TreeNode*> q; // BFS queue
        unordered_set <TreeNode*> visited; // visited array.
        q.push(target);
        visited.insert(target);
        int dist = 0; // Level indicator.
        while(!q.empty())
        {
            if(dist == k) // If its the kth BFS level then stop traversal since now queue contains all the nodes with distance k from target node.
                break;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end())
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            dist++;
        }
        vector <int> ans;
        while(!q.empty())
            ans.push_back(q.front()->val),
            q.pop();
        return ans;
    }
};