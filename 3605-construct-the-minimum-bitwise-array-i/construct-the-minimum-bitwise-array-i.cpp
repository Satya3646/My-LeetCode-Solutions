class Solution {
public:
    int getAns(int n)
    {
        if(n == 2) // only 2 has no solution.
            return -1;
        int tmp = n; // tmp variable to perform bit shifting.
        int mask = 1; // mask to flip needed bit.
        while(tmp & 1) // we move the one till the trailing ones in tmp are not over.
        {
            mask <<= 1; // move the one to left.
            tmp >>= 1;
        }
        mask >>= 1; // revert the one extra push due to initialization as one.
        return (n & (~mask)); // apply the mask to the number.
    }

    vector<int> minBitwiseArray(vector<int>& nums)
    {
        /* Adding a one to a number will flip all the trailing one to zeros and set the last 
        unset bit to 1, we take advantage of this fact and this method will give the smallest
        ans value, we will just flip the first set bit among the traling ones to zeros so that
        by addition of one it will be again set to one and OR value will be equal to nums[i]. */
        int n = nums.size();
        vector <int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = getAns(nums[i]);
        return ans;
    }
};