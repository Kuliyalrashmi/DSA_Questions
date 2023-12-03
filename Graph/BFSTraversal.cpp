/* BFS Traversal of Graph */
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>vis(n+1,0);
    vector<int>ans;
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    return ans;
}
