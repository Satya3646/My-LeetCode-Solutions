const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    bool canReachBottom(int day, int row, int col, vector <vector <int>> &grid)
    {
        vector <vector <bool>> visited(row, vector <bool> (col, false));
        queue <pair <int, int>> q;
        for(int i = 0; i < col; i++)
        {
            if(day < grid[0][i]) // not water yet on top row.
            {
                visited[0][i] = true;
                q.push({0, i});
            }
        }
        
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if(x == row-1) // if a cell in the bottom row is reached then return true.
                return true;
            for(int i = 0; i < 4; i++) // neighbors.
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < row && 0 <= ny && ny < col && grid[nx][ny] > day && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = col-1, // if only the bottom row keep getting sunk by water the one of the bottom will be reachable only till the (col-1)th day.
            high = row*(col-1); // if all the grid is sunk by water except the last col, that is the last day such that bottom row is reachable.

        vector <vector <int>> grid(row, vector <int> (col, 0));
        for(int i = 0; i < cells.size(); i++)
            grid[cells[i][0]-1][cells[i][1]-1] = i+1;

        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(canReachBottom(mid, row, col, grid)) // if mid can reach, go right to maximise it.
                low = mid+1;
            else
                high = mid-1;
        }
        return high;
    }
};