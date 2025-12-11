class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector <int> minX(n+1, INT_MAX), // min x coordinate for a given y coordinate.
                     maxX(n+1, INT_MIN), // max x coordinate for a given y coordinate.
                     minY(n+1, INT_MAX), // min y coordinate for a given x coordinate.
                     maxY(n+1, INT_MIN); // max y coordinate for a given x coordinate.
        for(vector <int> v : buildings) // Update the x and y limits.
        {
            int x = v[0];
            int y = v[1];
            minX[y] = min(minX[y], v[0]);
            maxX[y] = max(maxX[y], v[0]);
            minY[x] = min(minY[x], v[1]);
            maxY[x] = max(maxY[x], v[1]);
        }
        int ans = 0;
        for(vector <int> v : buildings)
        {
            int x = v[0];
            int y = v[1];
            // If the current point is within both x and y limits then its covered.
            if(minX[y] < x && x < maxX[y] &&
               minY[x] < y && y < maxY[x])
                ans++;
        }
        return ans;
    }
};