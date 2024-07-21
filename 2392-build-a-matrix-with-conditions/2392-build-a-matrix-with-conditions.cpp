class Solution {
public:
    void dfs(int node,vector<int>&visited,map<int,vector<int>>&adj,stack<int>&st,int& cycle)
    {
        visited[node]=1;
        for(auto neighbour:adj[node])
        {
            if(visited[neighbour]==0)
            {
                dfs(neighbour,visited,adj,st,cycle);
            }
            else if(visited[neighbour]==1)
            {
                cycle=1;
                return;
            }
        }
        visited[node]=2;
        st.push(node);
    }
    vector<int>toposort(vector<vector<int>>&mat,int k)
    {
        map<int,vector<int>>adj;
        for(auto i:mat)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
        vector<int>visited(k+1,0);
        stack<int>st;
        vector<int>order;
        int cycle=0;
        for(int i=1;i<=k;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,visited,adj,st,cycle);
                if(cycle==1)
                {
                    return {};
                }
            }
        }
        while(!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>topo_row=toposort(rowConditions,k);
        vector<int>topo_col=toposort(colConditions,k);
        vector<vector<int>>ans(k,vector<int>(k,0));
        if(topo_row.empty()||topo_col.empty())
        {
            return {};
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(topo_row[i]==topo_col[j])
                {
                    ans[i][j]=topo_row[i];
                }
            }
        }
        return ans;
    }
};