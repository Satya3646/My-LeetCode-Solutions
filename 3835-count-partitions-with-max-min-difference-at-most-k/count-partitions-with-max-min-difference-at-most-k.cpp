class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        /*
        We need a dp array and a prefix array.
        The dp[i] will contain the number of total partitions that can be made till 'i'
        prefix[i] is the sum of dp states from 0 to i.
        Adding a new value to the window changes the min and max hence to keep the difference <= k
        Hence we keep a variable j, the min index till which partitions result in diff <= k
        Thus for dp[i] the state update will be dp[i-1] + dp[i-2] + dp[i-3] +..... dp[j].
        Since we cant alway find this sum, we can just use prefix array to reduce complexity by n
        So here three things are happening : 
        1) window shrink when adding new element to keep diff <= k
        2) dp state update as prefix[i-1] - prefix[j]
        3) prefix update prefix[i] = prefix[i-1] + dp[i]
        */
        vector <long long> dp(n+1), prefix(n+1);
        dp[0] = prefix[0] = 1; // First partition is will always satisfy the condition since single element.
        multiset <int> s; // multiset for fast access of min and max values, alos it represents the window elements.
        int j = 0, mod = 1e9+7;
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]); // Add the new element to the window.
            while(j <= i && (*s.rbegin() - *s.begin()) > k) // Check window validity and increment j if condition is not satisfied.
                s.erase(s.find(nums[j])), // We need to erase single instance of the element hence get the iterator to the element, if value is given all the instances will be erased
                j++;
            // update dp[i+1] (1 based index) : dp[i+1] = prefix[i] - prefix[j-1] --> sum of dp from j to i.
            if(j > 0) 
                dp[i+1] = (prefix[i] - prefix[j-1] + mod) % mod;
            else
                dp[i+1] = prefix[i] % mod;
            prefix[i+1] = (prefix[i] + dp[i+1]) % mod; // Update prefix value as prefix[i+1] = prefix[i] + dp[i+1], here also 1 based indexing.
        }
        return dp[n];
    }
};