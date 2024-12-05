class Solution {
public:
     void dfs(vector<int> &vis, vector<vector<int>> graph, int node)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int x: graph[f]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> vis(n, 0);
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0], b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(vis, graph, source);
        return vis[destination];
    }  
};