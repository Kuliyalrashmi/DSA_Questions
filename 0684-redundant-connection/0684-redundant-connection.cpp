class Solution {
public:
    int find(int node,vector<int>&parent)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return find(parent[node],parent);
    }
    bool unioni(int u,int v,vector<int>&parent)
    {
         u=find(u,parent);
         v=find(v,parent);
         if(u==v)
         {
            return true;
         }
         parent[v]=u;
         return false; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,n);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            if(unioni(u,v,parent))
            {
                return {u,v};
            }
        }
        return {};
    }
};