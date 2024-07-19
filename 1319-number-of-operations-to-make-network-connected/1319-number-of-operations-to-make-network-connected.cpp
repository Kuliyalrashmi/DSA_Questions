class Solution {
public:
    int find(int u,vector<int>&parent)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=find(parent[u],parent);
    }
    void unions(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=find(u,parent);
        v=find(v,parent);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
            rank[v]++;
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
            rank[u]++;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        if(size<n-1)
        {
            return -1;
        }
        vector<int>parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        vector<int>rank(n,0);
        
        //count the edges that are available
        int available=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(find(u,parent)==find(v,parent))
            {
                available++;
            }
            else
            {
                unions(u,v,parent,rank);
            }
        }
        // check the number of components
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }
        return count-1;
    }
};