class Solution {
public:
    void dfs(int node,vector<int>&visited,vector<vector<int>>&adj)
    {
        visited[node]=1;
        for(auto neigh:adj[node])
        {
            if(!visited[neigh])
            {
                dfs(neigh,visited,adj);
                visited[neigh]=1;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        if(size<n-1)
        {
            return -1;
        }
        vector<vector<int>>adj(n);
        for(auto i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                 dfs(i,visited,adj);
                 count++;
            }
        }
        return count-1;
    }
};