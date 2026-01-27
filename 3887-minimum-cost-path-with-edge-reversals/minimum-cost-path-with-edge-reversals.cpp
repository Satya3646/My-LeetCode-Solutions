class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges)
    {
        vector <vector <pair <int, int>>> adj(n);
        for(vector <int> &v : edges)
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], 2*v[2]});
        }

        priority_queue <pair <int, int>,
                        vector<pair <int, int>>,
                        greater <pair <int, int>>> pq;
        vector <int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            if(dist[node] < d)
                continue;
            for(auto &[i, wt] : adj[node])
            {
                if(dist[i] > d + wt)
                {
                    dist[i] = d + wt;
                    pq.push({dist[i], i});
                }
            }
        }

        return dist[n-1] == INT_MAX? -1: dist[n-1];
    }
};