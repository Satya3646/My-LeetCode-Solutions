class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <vector <int>> reverseGraph(n); // reversed edges.
        vector <int> indegree(n); // indegree of nodes in reversed graph.
        queue <int> q;

        for(int i = 0; i < n; i++)
        {
            indegree[i] = graph[i].size(); // number of nodes pointing to 'i'.
            if(!indegree[i])
                q.push(i);
            for(int node : graph[i]) // take nodes in graph[i] (those coming out of i) and point them to i (towards i).
                reverseGraph[node].push_back(i);
        }

        vector <int> safeNodes;
        safeNodes.reserve(n);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int i : reverseGraph[node])
                if(!--indegree[i])
                    q.push(i);
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};