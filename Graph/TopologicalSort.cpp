/* Topological Sort Using DFS */

#include<stack>
void dfs(int node,vector<int>&visited,stack<int>&st,vector<int>adj[])
{
    visited[node]=1;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,st,adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int>adj[nodes];
    for(int i=0;i<edges;i++)
    {
        int u=graph[i][0];
        int v=graph[i][1];
        adj[u].push_back(v);
    }
    vector<int>visited(nodes);
    stack<int>st;
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}







/* Using BFS Kahn's Algorithm */
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int>adj[nodes];
    for(int i=0;i<edges;i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    vector<int>indegree(nodes,0);
    for(int i=0;i<nodes;i++)
    {
        for(auto j:adj[i])
        {
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<nodes;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto node:adj[front])
        {
            indegree[node]--;
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
    }
    return ans;

}
