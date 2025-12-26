const int mod = 1e9+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector <vector <pair <int, int>>> adj(n);
        for(vector <int> &v : roads)
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        vector <long long> dist(n, LLONG_MAX);
        vector <long long> ways(n, 0);
        priority_queue <pair <long long, int>, 
                        vector <pair <long long, int>>,
                        greater <pair <long long, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        ways[0] = 1;

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
                    ways[i] = ways[node];
                }
                else if(dist[i] == d + wt)
                    ways[i] = (ways[i] + ways[node]) % mod;
            }
        }

        return ways[n-1] % mod;
    }
};