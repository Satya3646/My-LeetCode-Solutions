class Solution {
public:
    bool bfs(int root, vector <vector <int>> &graph, vector <int> &color)
    {
        queue <int> q;
        color[root] = 1;
        q.push(root);
        while(!q.empty())
        {
            int node = q.front();
            int currentColor = color[node];
            q.pop();
            for(int i : graph[node])
            {
                if(!color[i])
                {
                    if(currentColor == 1)
                        color[i] = 2;
                    else
                        color[i] = 1;
                    q.push(i);
                }
                else if(color[i] == currentColor) 
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!color[i] && !bfs(i, graph, color))
                return false;
        }
        return true;
    }
};