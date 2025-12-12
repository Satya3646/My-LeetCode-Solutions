// class Solution {
// public:
//     int specialTriplets(vector <int> &nums)
//     {
//         int n = nums.size();
//         int mod = 1e9+7;
//         unordered_map <int, int> l,r; // maps to keep left and right counts.
//         l.reserve(n);
//         r.reserve(n);

//         for(auto i : nums) // Initially rmap has whole array.
//             r[i]++;
//         // Handle the zeros beforehand.
//         int zeros = r[0];
//         r.erase(0);
//         long long ans = (1LL * zeros * (zeros-1) * (zeros-2)) / 6; // nC3 for zeros.
//         ans %= mod;
//         if(zeros == n)
//             return ans;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] == 0) // Skip the zeros.
//                 continue;
//             r[nums[i]]--; // Remove current element(nums[j]) from right.
//             ans += l[2*nums[i]] * r[2*nums[i]];
//             ans %= mod;
//             l[nums[i]]++; // Add the current element to left before going to next iteration.
//         }
//         return ans;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1'000'000'007LL;
        int n = nums.size();
        unordered_map<long long,long long> left, right;
        left.reserve(n*2);
        right.reserve(n*2);

        for (int x : nums) right[x]++;

        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            // remove middle from right side
            right[nums[j]]--;
            if (right[nums[j]] == 0) right.erase(nums[j]);

            long long need = 2LL * nums[j];
            long long cl = 0, cr = 0;
            auto itl = left.find(need);
            if (itl != left.end()) cl = itl->second;
            auto itr = right.find(need);
            if (itr != right.end()) cr = itr->second;

            if (cl && cr) {
                ans = (ans + (cl % MOD) * (cr % MOD)) % MOD;
            }

            // move current into left
            left[nums[j]]++;
        }

        return static_cast<int>(ans);
    }
};