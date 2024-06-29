class Solution {
public:
    void DFS(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited)
    {
        visited[u]=true;
        for(auto neighbour:adj[u])
        {
            if(visited[neighbour]!=true)
            {
                DFS(neighbour,adj,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>result;
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            vector<int>anc;
            vector<bool>visited(n,false);
            DFS(i,adj,visited);
            for(int j=0;j<n;j++)
            {
                if(j==i)
                {
                    continue;
                }
                if(visited[j]==true)
                {
                    anc.push_back(j);
                }
            }
            result.push_back(anc);
        }
        return result;
    }
};