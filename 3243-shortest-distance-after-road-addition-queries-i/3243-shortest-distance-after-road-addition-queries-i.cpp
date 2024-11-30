class Solution {
public:
    int bfs(int n,map<int,vector<int>>&mp)
    {
        vector<int>distance(n,-1);
        distance[0]=0;
        queue<int>pq;
        pq.push(0);
        while(!pq.empty())
        {
            int front=pq.front();
            pq.pop();
            for(auto neighbour:mp[front])
            {
                if(distance[neighbour]==-1)
                {
                    distance[neighbour]=distance[front]+1;
                    pq.push(neighbour);
                }
            }
        }
      return distance[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        map<int,vector<int>>mp;
        for(int i=0;i<n-1;i++)
        {
            mp[i].push_back(i+1);
        }
        vector<int>ans;
        for(auto query:queries)
        {
            mp[query[0]].push_back(query[1]);
            int path=bfs(n,mp);
            ans.push_back(path);
        }
        return ans;
    }
};