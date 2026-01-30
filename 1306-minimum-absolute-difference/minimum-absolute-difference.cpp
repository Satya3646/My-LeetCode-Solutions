class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        int n = arr.size();

        // The difference between adjacent elements is minimized in sorted order.
        sort(arr.begin(), arr.end());
        vector <vector <int>> ans;
        int minDiff = INT_MAX;

        // The minimum difference first.
        for(int i = 1; i < n; i++)
            minDiff = min(minDiff, arr[i] - arr[i-1]);

        // Find the pairs of elements with minimum difference.
        for(int i = 1; i < n; i++)
            if(arr[i] - arr[i-1] == minDiff)
                ans.push_back({arr[i-1], arr[i]});
        return ans;
    }
};