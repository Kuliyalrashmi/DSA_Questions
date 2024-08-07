class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>path(n,0);
        dist[0]=0;
        path[0]=1;
        pq.push({0,0});
        long long mod=1e9+7;
        while(!pq.empty())
        {
            long long d=pq.top().first;
            long long n=pq.top().second;
            pq.pop();
            for(auto it:adj[n])
            {
                long long an=it.first;
                long long ew=it.second;
                if((d+ew)<dist[an])
                {
                    dist[an]=(d+ew);
                    pq.push({(d+ew),an});
                    path[an]=path[n];
                }
                else if((d+ew)==dist[an])
                {
                    path[an]=(path[an]+path[n])%mod;
                }
            }
        }
        return path[n-1]%mod;
    }
};