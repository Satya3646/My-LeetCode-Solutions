// All possible magic squares (Reflections and Rotations).
const vector <vector <vector <int>>> magic = {
    {{8,1,6},
     {3,5,7},
     {4,9,2}},

    {{6,1,8},
     {7,5,3},
     {2,9,4}},

    {{4,9,2},
     {3,5,7},
     {8,1,6}},

    {{2,9,4},
     {7,5,3},
     {6,1,8}},
     
    {{8,3,4},
     {1,5,9},
     {6,7,2}},

    {{4,3,8},
     {9,5,1},
     {2,7,6}},

    {{6,7,2},
     {1,5,9},
     {8,3,4}},

    {{2,7,6},
     {9,5,1},
     {4,3,8}}
};

/*
Looking at these magic squares we can see the patters.
1) The center is always '5'.
2) All 1-9 numbers must be present in the 3x3 grid.
3) Sum of diagonal is 15 i.e. sum of opposite corners must be 10.
4) Sum of each row is 15.
5) Sum of each col is 15.
If a sub-grid passes all these checks then only we can consider the sub-grid a magic square.
*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n < 3 || m < 3) // no 3x3 exists.
            return 0;

        int ans = 0; // count valid magic squares.
        int top = 0, bottom = 2; // row pointers.
        while(bottom < n)
        {
            int left = 0, right = 2; // column pointers.
            while(right < m)
            {
                // check if center is '5' or not.
                if(grid[top+1][left+1] == 5)
                {
                    vector <bool> vis(9, false); // indicates appearance of 1-9 numbers
                    for(int i = top; i <= bottom; i++)
                        for(int j = left; j <= right; j++)
                            if(1 <= grid[i][j] && grid[i][j] <= 9)
                                vis[grid[i][j]-1] = true;

                    bool unique = true; // true if all 1-9 are there in grid.
                    for(int i = 0; i < 9; i++)
                        unique &= vis[i];

                    if(unique) // if 1-9 are present the check the row, col, diagonal sums.
                    {
                        // sum of opposite corners must be 10 (diagonal check).
                        if(grid[top][left] + grid[bottom][right] == 10 &&
                        grid[top][right] + grid[bottom][left] == 10)
                        {
                            // each row sum must be 15.
                            bool rowFlag = true;
                            for(int i = top; i <= bottom; i++)
                            {
                                int sum = 0;
                                for(int j = left; j <= right; j++)
                                {
                                    sum += grid[i][j];
                                }
                                if(sum != 15)
                                {
                                    rowFlag = false;
                                    break;
                                }
                            }

                            // if all the rows have sum = 15 the check the columns.
                            if(rowFlag)
                            {
                                bool colFlag = true;
                                for(int i = left; i <= right; i++)
                                {
                                    int sum = 0;
                                    for(int j = top; j <= bottom; j++)
                                    {
                                        sum += grid[j][i];
                                    }
                                    if(sum != 15)
                                    {
                                        colFlag = false;
                                        break;
                                    }
                                }

                                // if all the columns also have sum = 15 the increment ans.
                                if(colFlag)
                                    ans++;
                            }
                        }
                    }
                }
                left++;
                right++;
            }
            top++;
            bottom++;
        }
        return ans;
    }
};