class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int rSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        int lSum = 0;
        for(int i = 0; i < n-1; i++)
        {
            lSum += nums[i];
            rSum -= nums[i];
            if(abs(lSum - rSum) & 1)
                continue;
            ans++;
        }
        return ans;
    }
};