class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(), [](vector <int> &a, vector <int> &b)
        {
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        vector <int> last = intervals[0];
        for(int i = 1; i < n; i++)
        {
            if(last[1] <= intervals[i][0]) // No overlap so update last
                last = intervals[i];
            else
                ans++;
        }
        return ans;
    }
};