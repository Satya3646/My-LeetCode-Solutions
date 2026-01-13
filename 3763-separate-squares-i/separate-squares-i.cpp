class Solution {
public:
    // This function calculates the are below the cut line.
    double getLowerHalf(double cut, int n, vector <vector <int>> &squares)
    {
        double area = 0;
        for(int i = 0; i < n; i++)
        {
            double y = squares[i][1];
            double l = squares[i][2];
            if(y < cut) // lower edge is under the cut.
            {
                if(y + l <= cut) // square is completely below the cut.
                    area += l * l;
                else // partially below the cut.
                    area += (cut - y) * l;
            }
        }
        return area;
    }

    double separateSquares(vector <vector <int>> &squares)
    {
        int n = squares.size();
        double low = 0.0;
        double high = 0.0;
        double halfArea = 0.0;

        for(int i = 0; i < n; i++) // calculates total area and updates high.
        {
            double y = squares[i][1];
            double l = squares[i][2];
            halfArea += l * l;
            high = max(high, y + l);
        }
        halfArea /= 2; // half the total area to get half area.

        while(high - low > 1e-5) // BS.
        {
            double mid = low + (high - low) / 2;
            double lowerArea = getLowerHalf(mid, n, squares); // get area below the cut at mid.
            if(lowerArea < halfArea) // if cut results in a small lower area the increase low.
                low = mid;
            else // cut give large lower area or equal to half area so decrease or minimize the cut coordinate.
                high = mid;
        }
        return high;
    }
};