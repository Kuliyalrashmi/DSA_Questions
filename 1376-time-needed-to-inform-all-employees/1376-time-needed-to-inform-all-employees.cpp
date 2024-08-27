class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int src,int &maxi,vector<int>&informTime,int &ans)
    {
         maxi=max(maxi,ans);
        for(auto neigh:adj[src])
        {
            ans+=informTime[src];
            dfs(adj,neigh,maxi,informTime,ans);
            ans-=informTime[src];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)
            {
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        int maxi=INT_MIN,ans=0;
        dfs(adj,headID,maxi,informTime,ans);
        return maxi;
    }
};