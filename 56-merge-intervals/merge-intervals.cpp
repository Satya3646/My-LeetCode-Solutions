class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector <vector <int>> ans;
        // Sort the intervals before merging since it is easier to merge intervals in order
        sort(intervals.begin(),intervals.end());
        /*
        Think of two intervals (a, b) and (c, d) now three cases car arise for these intervals
        1. No overlap on left side : b < c so (a, b) is to the left of (c, d) and they dont overlap
        2. Now since b < c cases are all handled (a, b) is now overlapping with (c, d) and the look like
           (a, c <= b, d), their overlap will continue till a crosses d i.e. they overlap for a <= d
        3. No overlap and on the right side, this is when a crosses d as a > d
        */
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] > ans.back()[1]) // No overlap c > b
                ans.push_back(intervals[i]);
            else // overlap is there so merge both intervals and update merged range to last element in answer
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
};