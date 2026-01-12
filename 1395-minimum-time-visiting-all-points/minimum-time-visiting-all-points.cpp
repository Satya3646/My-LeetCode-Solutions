class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalTime = 0;
        for(int i = 1; i < n; i++)
        {
            int dx = abs(points[i][0] - points[i-1][0]); // x-diff
            int dy = abs(points[i][1] - points[i-1][1]); // y-diff
            int time = min(dx, dy); // diagonal movement can be done min(dx, dy) times.
            time += abs(dx - dy); // final vertical/horizontal movement to account for extra dx or dy.
            totalTime += time;
        }
        return totalTime;
    }
};