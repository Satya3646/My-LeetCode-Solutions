class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> price(n, INT_MAX);
        vector <vector <pair <int, int>>> adj(n);
        for(vector <int> &v : flights)
            adj[v[0]].push_back({v[1], v[2]});
        queue <pair <int, int>> q;
        q.push({src, 0});
        price[src] = 0;

        while(!q.empty() && k-- >= 0)
        {
            int qs = q.size();
            while(qs--)
            {
                auto [node, cost] = q.front();
                q.pop();
                
                for(auto &[i, wt] : adj[node])
                {
                    if(price[i] > cost + wt)
                    {
                        price[i] = cost + wt;
                        q.push({i, price[i]});
                    }
                }
            }
        }

        if(price[dst] != INT_MAX)
            return price[dst];
        return -1;
    }
};