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
class BSTiterator 
{
public :
    stack <TreeNode*> stk;
    bool reverse;
    BSTiterator(TreeNode* root, bool reverse)
    {
        this->reverse =reverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode* node = stk.top();
        stk.pop();
        if(reverse)
            pushAll(node->left);
        else
            pushAll(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }

private :
    void pushAll(TreeNode* root)
    {
        if(!root)
            return;
        while(root)
        {
            stk.push(root);
            if(reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator l = BSTiterator(root, false); // left pointer of inorder(sorted).
        BSTiterator r = BSTiterator(root, true); // right pointer of inorder(sorted).
        int i = l.next(), j = r.next();
        while(i < j)
        {
            if(i + j == k)
                return true;
            if(i + j < k) // sum is too small so increment i.
                i = l.next();
            else // sum is too large so decrement j.
                j = r.next();
        }
        return false;
    }
};