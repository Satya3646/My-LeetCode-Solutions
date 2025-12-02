class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector <vector <int>> ans; // To build the answer
        int i = 0; // Iterator
        /*
        Think of two intervals (a, b) and (c, d) now three cases car arise for these intervals
        1. No overlap on left side : b < c so (a, b) is to the left of (c, d) and they dont overlap
        2. Now since b < c cases are all handled (a, b) is now overlapping with (c, d) and the look like
           (a, c <= b, d), their overlap will continue till a crosses d i.e. they overlap for a <= d
        3. No overlap and on the right side, this is when a crosses d as a > d
        */
        // Push the left non overlapping intervals to ans
        while(i < n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);
        // Merge the overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        // Push the merged inteval into ans
        ans.push_back(newInterval);
        // Push the right non overlapping intervals into the ans
        while(i < n && intervals[i][0] > newInterval[1])
            ans.push_back(intervals[i++]);
        return ans;
    }
};