class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int count=0;
        vector<int>dist(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:flights)
        {
            int u=i[0];
            int v=i[1];
            int cost=i[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        while(!q.empty()&&count<=k)
        {
            int size=q.size();
            while(size--)
            {
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto neighbour :adj[u])
                {
                    int v=neighbour.first;
                    int cost=neighbour.second;
                    if(dist[v]>d+cost)
                    {
                        dist[v]=d+cost;

                        q.push({v,(d+cost)});
                    }
                }
            }
            count++;
        }  
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};