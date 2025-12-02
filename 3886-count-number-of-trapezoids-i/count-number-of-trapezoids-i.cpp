class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod = 1e9 + 7;
        unordered_map <int, int> mp;
        for(vector <int> v : points)
            mp[v[1]]++;
        long long ans = 0;
        long long edgeSum = 0;
        for(pair <int, int> p : mp)
        {
            long long edges = (1LL*p.second) * (p.second-1) / 2;
            ans += ((edges % mod) * (edgeSum % mod)) % mod;
            ans %= mod;
            edgeSum += edges;
        }
        return ans;
    }
};