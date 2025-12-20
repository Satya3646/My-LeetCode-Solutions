const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue <pair <int, int>> q;

        /*
        1) Put all the ones on the boundary into the queue while marking them as visited.
        2) Since the board is a character board we can just use a sentinel value (-1) to mark visited without needing an explicit visited array.
        3) Now we can do BFS traversal from these boundary ones marking all their adjacent ones as '#'.
        4) At the end the remaining ones are the surrounded ones which we will count.
        */

        // Put all the ones on left and right boundary into queue and mark them as visited using a different value (-1).
        for(int i = 0; i < m; i++) 
        {
            if(grid[i][0] == 1)
                grid[i][0] = -1,
                q.push({i, 0});
            if(grid[i][n-1] == 1)
                grid[i][n-1] = -1, 
                q.push({i, n-1});
        }

        // Put all the ones on top and bottom boundary into queue and mark them as visited using a different value (-1).
        for(int i = 0; i < n; i++)
        {
            if(grid[0][i] == 1)  
                grid[0][i] = -1, 
                q.push({0, i});
            if(grid[m-1][i] == 1)
                grid[m-1][i] = -1, 
                q.push({m-1, i});
        }

        while(!q.empty())
        {
            int qs = q.size();
            for(int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front(); // Unpack the coordinates.
                q.pop();
                for(int j = 0; j < 4; j++) // Iterate the adjacents.
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 1) // if this is 1 that is adjacent to a boundary 1 the marks this a visited using -1.
                        grid[nx][ny] = -1, 
                        q.push({nx, ny});
                }
            }
        }

        int ans = 0;
        // After the traversal completed all the ones left are the surrounded ones (not connected to any boundary), so we can count them
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};