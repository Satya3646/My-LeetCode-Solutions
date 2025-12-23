class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        // sort the events based on start times.
        sort(events.begin(), events.end());

        vector <int> suffixMax(n, INT_MIN); // vector to return the suffix max values.
        // suffixMax[i] --> max value in the range i to n-1.
        suffixMax[n-1] = events[n-1][2];
        for(int i = n-2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i+1], events[i][2]);
        
        int maxValue = INT_MIN;
        for(int i = 0; i < n; i++) // loop to fix the first event as ith event, we will choose the second even using binary search.
        {
            // find an even such that it starts after the current event.
            auto it = upper_bound(events.begin(), events.end(), vector <int> {events[i][1], INT_MAX, INT_MAX}); // INT_MAX is used to ensure that only those with larger start time than the end time of the current event are considered(prevents those with the same start time as current even but a larger endtime from being considered).
            if(it != events.end())
                maxValue = max(maxValue, events[i][2] + suffixMax[it - events.begin()]);
            else
                maxValue = max(maxValue, events[i][2]);
        }
        return maxValue;
    }
};