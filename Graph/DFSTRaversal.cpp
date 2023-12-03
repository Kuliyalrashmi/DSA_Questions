/* DFS Traversal of Graph */
void dfs(int node,vector<int>&visited,vector<int>adj[],vector<int>&temp)
{
    visited[node]=1;
    temp.push_back(node);
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int>adj[V];
    for(auto i:edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<vector<int>>ans;
    vector<int>vis(V+1,0);
    for(int i=0;i<V;i++)
    {
       vector<int>temp;
       if(!vis[i])
       {
           dfs(i,vis,adj,temp);
           ans.push_back(temp);
       } 
    }
    return ans;
}
