const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int orangesRotting(vector <vector <int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int fresh = 0;
        queue <pair <int, int>> rotten;

        // push the rotten oranges and count the fresh oranges.
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                    rotten.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        // Start the bfs traversal.
        while(!rotten.empty())
        {
            int qs = rotten.size();
            for(int i = 0; i < qs; i++)
            {
                auto [x, y] = rotten.front(); // extract the coordinates.
                rotten.pop();

                // infect the top, bottom, right, left oranges which are fresh.
                for(int j = 0; j < 4; j++)
                {
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if(0 <= newX && newX < m && 0 <= newY && newY < n && grid[newX][newY] == 1)
                    {
                        fresh--; // dercrement since its rotten now.
                        grid[newX][newY] = 2; // Update grid to rotten state.
                        rotten.push({newX, newY});
                    }
                }
            }
            if(!rotten.empty()) // if some oranges were rotten during current iteration only then increase the time, if no new oranges were rotten during current iteration we cant increase time.
                time++;
        }

        return fresh? -1: time;
    }
};