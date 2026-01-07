const int mod = 1e9+7;

class Solution {
public:
    long long dfs(TreeNode* root, long long totalSum, long long &ans)
    {
        if(!root)
            return 0;
        
        // if we cut off the left subtree.
        long long lsum = dfs(root->left, totalSum, ans);
        ans = max(ans, (totalSum - lsum) * lsum);
        
        // if we cut off the right sumbtree.
        long long rsum = dfs(root->right, totalSum, ans);
        ans = max(ans, (totalSum - rsum) * rsum);

        // return sum of current tree for upper levels.
        return root->val + lsum + rsum;
    }

    int maxProduct(TreeNode* root)
    {
        long long ans = 0;
        // get the total sum of the tree first.
        long long totalSum = dfs(root, 0, ans); 
        // update of ans during this dfs will notupdate since -lsum * lsum will be -ve 
        // and less than ans so ans will remain as 0.
        
        dfs(root, totalSum, ans); // real update of ans is done here. 
        return ans % mod;
    }
};