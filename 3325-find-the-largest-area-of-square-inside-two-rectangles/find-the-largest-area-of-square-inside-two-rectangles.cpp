class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSide = 0;
        
        // Iterate over all distinct pairs of rectangles.
        for(int i = 0; i < n; i++) // select Rectangle 1.
        {
            for(int j = i+1; j < n; j++) // select Rectangle 2.
            {
                // Bottom Left Corner of intersection.
                int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);

                // Top Right Corner of the intersection.
                int x2 = min(topRight[i][0], topRight[j][0]);
                int y2 = min(topRight[i][1], topRight[j][1]);
                
                // Check if they intersect.
                if(x1 < x2 && y1 < y2)
                {
                    // we take the min intersection region side to form a square.
                    maxSide = max(maxSide, 1LL * min(x2 - x1, y2 - y1));
                }
            }
        }

        // return the area.
        return maxSide * maxSide;
    }
};