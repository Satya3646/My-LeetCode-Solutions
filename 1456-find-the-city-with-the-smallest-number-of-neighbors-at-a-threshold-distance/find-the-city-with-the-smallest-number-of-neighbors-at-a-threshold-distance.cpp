class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector <int>> dist(n, vector <int> (n, INT_MAX)); // dist vector for all i,j.
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        for(vector <int> &v : edges)
            dist[v[0]][v[1]] = dist[v[1]][v[0]] = v[2];

        // Floyd Warshall to updates shortest dist vector.
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) // if k is not intermediate then skip this path.
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minCity = -1;
        int minCnt = INT_MAX;
        for(int i = 0; i < n; i++) // count number of cities that can be reached from i within distance treshold.
        {
            int cnt = 0;
            for(int d : dist[i])
                if(d <= distanceThreshold)
                    cnt++;
            if(cnt <= minCnt)
            {
                minCity = i;
                minCnt = cnt;
            }
        }
        return minCity;
    }
};