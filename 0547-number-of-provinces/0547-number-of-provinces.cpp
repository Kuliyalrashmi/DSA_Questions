class Solution {
public:
    void dfs(vector<int>&visited,int src,vector<int>list[])
    {
        visited[src]=1;
        for(auto neighbour:list[src])
        {
            if(!visited[neighbour])
            {
                dfs(visited,neighbour,list);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&&i!=j)
                {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        int provinces=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]!=1)
            {
                provinces++;
                dfs(visited,i,list);
            }
        }
        return provinces;
    }
};