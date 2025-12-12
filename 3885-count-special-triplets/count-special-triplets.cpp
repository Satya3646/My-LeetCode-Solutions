class Solution {
public:
    int specialTriplets(vector <int> &nums)
    {
        int n = nums.size();
        int mod = 1e9+7;
        unordered_map <int, int> l,r; // maps to keep left and right counts.
        l.reserve(n);
        r.reserve(n);

        for(auto i : nums) // Initially rmap has whole array.
            r[i]++;
        // Handle the zeros beforehand.
        int zeros = r[0];
        r.erase(0);
        long long ans = (1LL * zeros * (zeros-1) * (zeros-2)) / 6; // nC3 for zeros.
        ans %= mod;
        if(zeros == n)
            return ans;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) // Skip the zeros.
                continue;
            r[nums[i]]--; // Remove current element(nums[j]) from right.
            int left = 0, right = 0;
            if(l.find(2*nums[i]) != l.end())
                left = l[2*nums[i]];
            if(r.find(2*nums[i]) != r.end())
                right = r[2*nums[i]];
            if(left && right)
                ans = (ans + (1LL * left * right)) % mod;
            l[nums[i]]++; // Add the current element to left before going to next iteration.
        }
        return ans;
    }
};