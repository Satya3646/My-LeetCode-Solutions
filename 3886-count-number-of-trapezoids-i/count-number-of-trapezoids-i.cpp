class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod = 1e9 + 7; // Modulo Value
        unordered_map <int, int> mp; // Map to store number of points on same horizontal line
        for(vector <int> v : points)
            mp[v[1]]++;
        // The size of map will be number of horizontal lines, and the values will be number of points on those lines
        // We can pick any two lines, then pick any two points from one line and two from another line the 4 points will definitely form a trapezoid. Hence finding the total is the answer.
        long long ans = 0;
        long long edgeSum = 0;
        // Clever combination instead of using two loops
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