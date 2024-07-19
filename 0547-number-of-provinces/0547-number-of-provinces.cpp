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
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<int>parent(n);
       vector<int>rank(n,0);
       for(int i=0;i<n;i++)
       {
           parent[i]=i;
       }
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               if(isConnected[i][j]==1)
               {
                   unions(i,j,parent,rank);
               }
           }
       } 
       int provinces=0;
       for(int i=0;i<n;i++)
       {
           if(parent[i]==i)
           {
               provinces++;
           }
       }
       return provinces; 
    }
};