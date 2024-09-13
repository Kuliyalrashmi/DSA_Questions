class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adj,vector<int>&color,int index)
    {
        queue<int>q;
        q.push(index);
        color[index]=1;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto neighbour:adj[curr])
            {
                if(color[neighbour]==-1)
                {
                    if(color[curr]==1)
                    {
                        color[neighbour]=2;
                    }
                    else
                    {
                        color[neighbour]=1;
                    }
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[curr])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto i:dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(adj,color,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};