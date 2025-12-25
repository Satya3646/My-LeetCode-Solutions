const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector <vector <int>> effort(n, vector <int> (m, INT_MAX));
        priority_queue <pair <int, pair <int, int>>,
                        vector <pair <int, pair <int, int>>>,
                        greater <pair <int, pair <int, int>>>> pq;
        pq.push({0, {0, 0}});
        effort[0][0] = 0;
        
        while(!pq.empty())
        {
            auto [dist, xy] = pq.top();
            auto [x, y] = xy;
            pq.pop();

            if(effort[x][y] < dist) // if the effort of current node is already less then node need to process, stale node pushed so skip it. 
                continue;

            for(int i = 0; i < 4; i++) // neighbors.
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < m)
                {
                    if(effort[nx][ny] > max(dist, abs(heights[x][y] - heights[nx][ny])))
                    {
                        effort[nx][ny] = max(dist, abs(heights[x][y] - heights[nx][ny]));
                        pq.push({effort[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};