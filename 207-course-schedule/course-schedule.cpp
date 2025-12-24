class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector <vector <int>> adj(n);
        vector <int> indegree(n, 0);
        for(vector <int> &edge : prerequisites)
        {
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }

        queue <int> q;
        vector <int> topo;
        topo.reserve(n);
        for(int i = 0; i < n; i++) // put all zero indegree nodes into  queue.
            if(!indegree[i])
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i : adj[node])
            {
                if(!--indegree[i]) // if indegree became zero then push to queue.
                    q.push(i);
            }
        }
        
        // if all nodes are processed successfully then return true.
        return topo.size() == n;
    }
};