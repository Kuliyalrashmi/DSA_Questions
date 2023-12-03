/* Given an Undirected Graph of V vertices and E edges .Return True if the graph contains cycle or not , else return False */
class Graph {

public:
    bool check(int node,vector<int>&visited,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        visited[node]=1;
        q.push({node,-1});
        while(!q.empty())
        {
            int front=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto i:adj[front])
            {
                if(!visited[i])
                {
                    q.push({i,front});
                    visited[i]=1;
                }
                else if(parent!=i)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(check(i,visited,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
