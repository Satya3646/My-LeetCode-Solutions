class Solution {
public:
    int shortestPathBinaryMatrix(vector <vector <int>> &grid)
    {
        int n = grid.size();
        vector <vector <int>> ans(n, vector <int> (n, -1));
        queue <pair <int, int>> q;
        if(!grid[0][0]) // push only if starting node is a '0'.
        {    
            q.push({0, 0});
            ans[0][0] = 1;
        }
        int dist = 1; // since we need the count of 0's in path and not the edges.

        while(!q.empty())
        {
            int qs = q.size();
            dist++;
            while(qs--)
            {
                auto [x, y] = q.front();
                q.pop();
                // check the neighbors.
                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if(i || j) // if both are zero we must skip.
                        {
                            int nx = x + i;
                            int ny = y + j;
                            // if neighbor is a 0 and not visited yet the push to queue.
                            if(0 <= nx && nx < n && 0 <= ny && ny < n && !grid[nx][ny] && ans[nx][ny] == -1)
                            {
                                ans[nx][ny] = dist;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return ans[n-1][n-1]; // it will remain as -1 if it was not reachable else shorterst distance will be returned.
    }
};