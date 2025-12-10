/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root)
            return "N";
        // We will serialize the tree is BFS order, accounting for the null nodes in between.
        // This way we will get the string is level by level order.
        queue <TreeNode*> q; // BFS queue.
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node == nullptr)
                {
                    s.append("N,");
                    continue;
                }
                s.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        // The resulting string will have trailiing Ns which are due to the null leave nodes.
        // We can safely remove them to shorten the serialized string.
        int n = s.size();
        int i = s.size()-1;
        while(!('0' <= s[i] && s[i] <= '9'))
            i--;
        s = s.substr(0, i+1);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &s) {
        stringstream ss(s); // Stream to extract node values one after another.
        queue <TreeNode*> q;
        if(s[0] == 'N')
            return nullptr;
        string x;
        getline(ss, x, ','); // Extract root value.
        TreeNode* root = new TreeNode(stoi(x));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* parent = q.front();
            q.pop();
            if(getline(ss, x, ',') && x != "N") // if stream has not ended and the extracted value is not null the add it to the tree and queue.
            {    
                parent->left = new TreeNode(stoi(x));
                q.push(parent->left);
            }
            if(getline(ss, x, ',') && x != "N")
            {
                parent->right = new TreeNode(stoi(x));
                q.push(parent->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));