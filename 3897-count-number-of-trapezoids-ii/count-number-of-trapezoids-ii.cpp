class Solution {
public:
    long long key(int x, int y)
    {
        return ((long long)x << 32) | (unsigned int)y;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        /*
        To solve this problem we need to diffrentiate points based on the line they are on as well as
        the slope of the line.
        First we differentiate the lines baesd on the slope, so now we have lines grouped based on slope
        But there can be may lines with the same slope value we need to differentiate them too.
        We use the concept of y-intercept to differentiate the parallel lines.
        The mapping looks something like the following : 
        Map (Key : Slope)
        │
        ├── Slope {1, 1} (Diagonal 45°)
        │   │
        │   ├── Line Constant 0  (e.g., y=x)      -> Count: 3 segments
        │   ├── Line Constant 5  (e.g., y=x+5)    -> Count: 2 segments
        │   └── Line Constant -2 (e.g., y=x-2)    -> Count: 1 segment
        │       ^
        │       We calculate pairs HERE: (3*2) + (3*1) + (2*1)
        │
        ├── Slope {1, 0} (Vertical)
        │   │
        │   ├── Line Constant 10 (x=10) -> Count: 4 segments
        │   └── (No other lines)        -> Count: 0 trapezoids
        */
        unordered_map <long long, unordered_map <int, int>> mp;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1 ; j < n; j++)
            {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx < 0 || (dx == 0 && dy < 0))// Maintain correct sign for dx(+ve) & dy(-ve if needed)
                {
                    dx = -dx;
                    dy = -dy;
                }
                int g = gcd(abs(dx), abs(dy)); // Normalize to have dx and dy in base fraction form
                dx /= g;
                dy /= g;
                int c = dy * points[i][0] - dx * points[i][1]; // Calculate line constant c = dy*x - dx*y
                mp[key(dx, dy)][c]++; // Update mapping : slope --> line --> points pair count
            }
        }
        // Now the mapping has grouped the segments based on the line they lie on and the slope of line 
        long long trapezoids = 0; // String the number of trapezoids
        // Taking any two lines with same slope, different line constants will result in a trapezoids
        // So calculate the number of trapezoids accordingly
        for(auto &slope: mp) // Iterate over the slopes
        {
            long long sum = 0;
            // Iterate over the lines with same slopes and find the number of trapezoids we can form
            // Line1 has e1 edge and Lin2 had e2 edges then e1.e2 trapezoids can form
            // Instead of using nested loops we use clever accumulation sum, product
            for(auto &p : slope.second)
            {
                trapezoids += sum * p.second;
                sum += p.second;
            }
        }
        // The parallellograms will be counted twice so we need to exclude them
        // Two non parallel segments having the same midpoints will form a paralellogram so count and
        // exclude them accordingly.
        unordered_map <long long, int> midpoints; // Keep number of points with same midpoint
        unordered_map <long long, unordered_map <long long, int>> directions; // keep number of points with same midpoint but different slope : midpoint to slope to segment count
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1;j < n; j++)
            {
                // Midpoint calculation
                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                // Slope calculation
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx < 0 || (dx == 0 && dy < 0))// Maintain correct sign for dx(+ve) & dy(-ve if needed)
                {
                    dx = -dx;
                    dy = -dy;
                }
                int g = gcd(abs(dx), abs(dy)); // Normalize to have dx and dy in base fraction form
                dx /= g;
                dy /= g;
                if(midpoints.find(key(mx, my)) != midpoints.end()) // Check if other segments with same midpoint exist in the map
                    trapezoids -= (midpoints[key(mx, my)] - directions[key(mx, my)][key(dx, dy)]);
                    // If there are segment with same midpoint then subtract those having different slope than the current segment only
                    // Segments with same midpoint but different midpoint must be subtracted
                midpoints[key(mx, my)]++;
                directions[key(mx, my)][key(dx, dy)]++;
            }
        }
        return trapezoids;
    }
};